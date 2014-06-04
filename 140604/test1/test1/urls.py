from django.conf.urls import patterns, include, url

from django.contrib import admin
from test1.view import hello,homepage,ctime
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'test1.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^admin/', include(admin.site.urls)),
    url(r'^hello/$',hello),
    url(r'^$',homepage),
    url(r'^time/$',ctime),
)
