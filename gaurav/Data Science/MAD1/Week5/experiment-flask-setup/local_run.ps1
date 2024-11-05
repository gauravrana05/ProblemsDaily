# This is a PowerShell script for setting up and activating the virtual environment

Write-Output "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
Write-Output "Welcome to the setup. This will set up the local virtual environment."
Write-Output "And then it will install all the required Python libraries."
Write-Output "You can rerun this without any issues."
Write-Output "-----------------------------------------------------------"

# Check if the virtual environment folder exists
if (Test-Path -Path ".\.env") {
    Write-Output "Enabling virtual environment"
} else {
    Write-Output "No virtual environment found. Please run setup.sh first."
    exit
}

# Activate virtual environment
& .\.env\bin\Activate.ps1

# Run main.py
python main.py

# Deactivate virtual environment
deactivate
