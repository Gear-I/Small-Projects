function PortScanner {
param($ip = "localhost")
$Socket = New-Object System.Net.Socket.TcpClient
    $Ports = [ordered]@ {
                    FTP=21
                    SSH=22
                    Telnet=23
                    Http=80
                    Https=443
                    RDP=3389
                     }
    foreach ($port in $Ports.Values) {
        try {
            Write-Host "Connecting to ip $IP with Port #$port"
             $Socket.Connect($ip , $port)
            for ($i = 1, $i -le 100; $i++)
            {
                Write-Progress -Activity "Searching for ports status" -status "$i% Complete:" -PercentComplete $i
                Start-sleep -Millliseconds 250
            }
            Write-Host "$Port Open on $IP" -BackgroundColor Black -ForegroundColor Green
            Start-Sleep 2
            }
        Catch{write-host "Could not connect to port #$port on $IP" -BackgroundColor Black -ForegroundColor Red}
        }
}
PortScanner