import time
from .accounts import list_accounts
from .ledger import add_transaction
from .utils import validate_account_number, validate_amount

def begin_transaction(credit_account, debit_account, amount):
    t0 = time.time()
    success = False

    if not validate_account_number(debit_account) or not validate_account_number(credit_account):
        print("Invalid account number format.")
        return success

    if not validate_amount(amount):
        print("Invalid amount. Must be a positive number.")
        return success

    accounts = list_accounts()
    debit_account_record = next((acc for acc in accounts if acc['Account_no'] == debit_account), None)
    credit_account_record = next((acc for acc in accounts if acc['Account_no'] == credit_account), None)

    if debit_account_record and credit_account_record:
        if int(debit_account_record['Balance']) >= int(amount):
            debit_account_record['Balance'] = str(int(debit_account_record['Balance']) - int(amount))
            credit_account_record['Balance'] = str(int(credit_account_record['Balance']) + int(amount))

            add_transaction(debit_account, credit_account, amount, 'D')
            add_transaction(credit_account, debit_account, amount, 'C')

            success = True

    t1 = time.time()
    print('Time Elapsed:', (t1 - t0) * 1000, 'milliseconds')
    return success
