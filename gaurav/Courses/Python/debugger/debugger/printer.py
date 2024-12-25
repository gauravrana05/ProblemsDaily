import json
from colorama import Fore, Style, init

# Initialize colorama
init(autoreset=True)

def debug(name, value, indent=0):
    """
    Debug function to print variables, dictionaries, lists, tuples, and their nested forms with colors.
    
    Args:
    name (str): The name of the variable.
    value (any): The value of the variable.
    indent (int): The indentation level (used for nested structures).
    """
    spacing = ' ' * indent
    if isinstance(value, dict):
        print(f"{spacing}{Fore.GREEN}{name}: {Fore.CYAN}{{{Fore.RESET}")
        for key, val in value.items():
            debug(key, val, indent + 4)
        print(f"{spacing}{Fore.CYAN}}}{Fore.RESET}")
    elif isinstance(value, list):
        print(f"{spacing}{Fore.GREEN}{name}: {Fore.CYAN}[{Fore.RESET}")
        for idx, item in enumerate(value):
            debug(f"[{idx}]", item, indent + 4)
        print(f"{spacing}{Fore.CYAN}]{Fore.RESET}")
    elif isinstance(value, tuple):
        print(f"{spacing}{Fore.GREEN}{name}: {Fore.CYAN}({Fore.RESET}")
        for idx, item in enumerate(value):
            debug(f"({idx})", item, indent + 4)
        print(f"{spacing}{Fore.CYAN}){Fore.RESET}")
    else:
        print(f"{spacing}{Fore.GREEN}{name}: {Fore.MAGENTA}{value}{Fore.RESET}")
