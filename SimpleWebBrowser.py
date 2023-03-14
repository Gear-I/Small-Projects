# importing neccessary libraries
import os
import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtWebEngineWidgets import *
from PyQt5.QtPrintSupport import *

# Creating Main Window for Browser

class MainWindow(QMainWindow):

	# Constructor
	def _init_(self, *args, **kwargs):
		super(MainWindow, self)._init_(*args, **kwargs)

		# Creating a Web Engine View
		self.broswer = QWebEngineView()

		# Default URL as Google
		self.browser.seturl(QUrl("https://google.com"))

		# adding action when url gets changed
		self.browser.urlchange.connect(self.update_urlbar)

		# adding action when loading is completed
		self.broswer.loadfinish.connect(self.update_title)

		# set broswer as central widget or main window 
		self.setCentralWidget(self.broswer)
		#Status Bar
		self.status = QStatusBar()
		#Adding Status to Main Window
		self.setStatusBar(self.status)

		#Toolbar for Navigation
		navtb = QToolBar("Navigation")

		#ToolBar to Main Window
		self.addtoolbar(navtb)



		#loop

		app.exec_()


