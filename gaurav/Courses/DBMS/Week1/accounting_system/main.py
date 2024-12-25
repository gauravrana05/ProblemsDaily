from accounting_system.accounts import add_account, list_accounts
from accounting_system.ledger import display_transaction_history
from accounting_system.transactions import begin_transaction

def main():
    while True:
        choice = int(input("1. Add Account\n2. View Transaction History\n3. Make a Transaction\n4. Exit\nChoose an option: "))
        
        if choice == 1:
            account_no = input("Account No: ")
            name = input("Name: ")
            address = input("Address: ")
            phone_no = input("Phone No: ")
            pan = input("PAN: ")
            account_type = input("Account Type: ")
            balance = input("Initial Balance: ")
            add_account(account_no, name, address, phone_no, pan, account_type, balance)
            print("Account added successfully.")

        elif choice == 2:
            account_no = input("Enter Account No: ")
            history = display_transaction_history(account_no)
            for record in history:
                print(record)

        elif choice == 3:
            debit_account = input("Debit Account No: ")
            credit_account = input("Credit Account No: ")
            amount = input("Amount: ")
            if begin_transaction(credit_account, debit_account, amount):
                print("Transaction successful.")
            else:
                print("Transaction failed. Check account details.")

        elif choice == 4:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
