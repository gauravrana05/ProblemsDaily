import csv
from .config import LEDGER_FILE, col_name_Ledger
import logging

# Configure logging
logging.basicConfig(filename='transactions.log', level=logging.INFO)

def add_transaction(account1, account2, amount, transaction_type):
    try:
        with open(LEDGER_FILE, 'a+', newline='') as f_obj:
            f_writer = csv.DictWriter(f_obj, fieldnames=col_name_Ledger)
            f_writer.writerow({'Account1': account1, 'Account2': account2,
                               'Amount': amount, 'D/C': transaction_type})
        log_transaction("Add Transaction", f"{transaction_type} from {account1} to {account2}: {amount}")
    except Exception as e:
        print(f"Error adding transaction: {e}")

def display_transaction_history(account_no):
    transactions = []
    try:
        with open(LEDGER_FILE, 'r') as f_obj:
            f_reader = csv.DictReader(f_obj)
            for record in f_reader:
                if record['Account1'] == account_no or record['Account2'] == account_no:
                    transactions.append(record)
    except FileNotFoundError:
        print("Ledger file not found.")
    except Exception as e:
        print(f"Error reading ledger: {e}")
    return transactions
