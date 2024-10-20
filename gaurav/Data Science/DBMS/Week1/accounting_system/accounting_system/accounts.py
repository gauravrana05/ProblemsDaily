import csv
import os
from .config import ACCOUNTS_FILE, col_name_Account
import logging

# Configure logging
logging.basicConfig(filename='transactions.log', level=logging.INFO)

def add_account(account_no, name, address, phone_no, pan, account_type, balance):
    try:
        with open(ACCOUNTS_FILE, 'a+', newline='') as f_obj:
            f_writer = csv.DictWriter(f_obj, fieldnames=col_name_Account)
            f_writer.writerow({'Account_no': account_no, 'Name': name, 'Address': address,
                               'Phone_no': phone_no, 'PAN': pan, 'A/C type': account_type,
                               'Balance': balance})
        log_transaction("Add Account", f"Account {account_no} added successfully.")
    except Exception as e:
        print(f"Error adding account: {e}")

def list_accounts():
    accounts = []
    try:
        with open(ACCOUNTS_FILE, 'r') as f_obj:
            f_reader = csv.DictReader(f_obj)
            for record in f_reader:
                accounts.append(record)
    except FileNotFoundError:
        print("Accounts file not found.")
    except Exception as e:
        print(f"Error reading accounts: {e}")
    return accounts

def log_transaction(action, details):
    logging.info(f"{action}: {details}")
