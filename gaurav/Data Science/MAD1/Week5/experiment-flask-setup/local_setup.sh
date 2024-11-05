#! /bin/sh
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "Welcome to the setup. This will setup the local virtual env."
echo "And then it will install all the required python libraris."
echo "You can rerun this without any issues."
echo "-----------------------------------------------------------"
if [ -d ".env" ];
then 
  echo ".env folder exists."
else
  echo "creating .env"
  python3 -m venv .env
fi

#Activate virtual env

.\.env\Scripts\activate

#Upgrade PIP
pip install --upgrade pip
pip install -r requirements.txt

deactivate