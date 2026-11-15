from django.shortcuts import render
from rest_framework import generics
from .models import Ticket
from .serializers import TicketSerializer
# Create your views here.
class TicketList(generics.ListCreateAPIView):
    queryset = Ticket.objects.all()
    serializer_class = TicketSerializer