#! /bin/sh
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "Welcome to the setup. This will setup the local virtual env."
echo "And then it will install all the required python libraris."
echo "You can rerun this without any issues."
echo "-----------------------------------------------------------"
if [-d ".env" ];
then 
  echo "Enabling virtual env"
else
  echo "No virtual env. Please run setup.sh first"
  exit N
fi

#Activate virtual env

.\env\Scripts\activate

python3 main.py
deactivate