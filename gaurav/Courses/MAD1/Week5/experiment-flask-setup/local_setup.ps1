# PowerShell script to set up and activate the virtual environment

Write-Output "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
Write-Output "Welcome to the setup. This will set up the local virtual environment."
Write-Output "And then it will install all the required Python libraries."
Write-Output "You can rerun this without any issues."
Write-Output "-----------------------------------------------------------"

# Check if the .env folder exists
if (Test-Path -Path ".\.env") {
  Write-Output ".env folder exists."
}
else {
  Write-Output "Creating .env folder..."
  python -m venv .env
}

# Activate the virtual environment
& .\.env\bin\Activate.ps1

# Upgrade pip and install required packages
Write-Output "Upgrading pip..."
pip install --upgrade pip

Write-Output "Installing dependencies from requirements.txt..."
pip install -r requirements.txt

# Deactivate the virtual environment
deactivate
