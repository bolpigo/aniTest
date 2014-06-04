from django.http import HttpResponse
import datetime
def ctime(req):
	curtime=datetime.datetime.now()
	txt="it's %s." % curtime
	return HttpResponse(txt);
def hello(req):
	return HttpResponse("<h1>Hello World!</h1>")
def homepage(req):
	return HttpResponse("this is homepage!")
