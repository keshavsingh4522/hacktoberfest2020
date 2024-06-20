from rest_framework import serializers
from EmployeeApp.models import Department,Employees

class DepartmentSerializer(serializers.ModelSerializer):
    class Meta:
        model=Department 
        fields=('DepartmentId','DepartmentName')

class EmployeeSerializer(serializers.ModelSerializer):
    class Meta:
        model=Employees
        fields=('EmployeeId','EmployeeName','Department','DateOfJoining','PhotoFileName')