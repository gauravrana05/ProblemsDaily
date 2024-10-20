# utils.py

def validate_account_number(account_no):
    # Check if the account number is valid (e.g., numeric and of certain length)
    return account_no.isnumeric() and len(account_no) == 10  # Example validation

def validate_amount(amount):
    # Check if the amount is a positive number
    return amount.isdigit() and int(amount) > 0
