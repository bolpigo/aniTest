from django.shortcuts import render_to_response

# Create your views here.
def index(req):
	return render_to_response('index.html',{'user_stylesheet':'css/user.css'})
