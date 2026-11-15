from django.urls import path
from . import views 

urlpatterns = [
    path('tickets/', views.TicketList.as_view()),
]