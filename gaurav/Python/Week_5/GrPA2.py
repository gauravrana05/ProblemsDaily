def total_price(fruit_prices: dict, purchases) -> float:
    '''
    Compute the fruit prices give the quantity of each fruit. Do not use the sum function.

    Arguments:
    fruit_prices: dict - fruit name as key and price as value
    purchases: list[tuple] - as list of tuples of (fruit, quantity)

    Return:
    total_price: float
    '''

    total = 0
    for fruit, quantity in purchases:
        total+= fruit_prices[fruit]*quantity
    return total

def total_price_no_loops(fruit_prices: dict, purchases) -> float:
    '''
    Compute the total price without loops.
    '''

    return sum(
        fruit_prices[fruit]*quantity
        for fruit, quantity in purchases
    )

def find_cheapest_fruit(fruit_prices:dict) -> str:
    '''
    Find the cheapest fruit from the fruit_prices dict, do not use min function

    Arguments:
    fruit_prices: dict - fruit name as key and price as value

    Return:
    cheapest_fruit: str - the fruit with the lowest price
    '''

    fruit_price_tuples = list(fruit_prices.items())
    
    min_fruit, min_price = fruit_price_tuples[0]
    for fruit, price in fruit_price_tuples[1:]:
        if price<min_price:
            min_fruit,min_price = fruit, price
    return min_fruit

def find_cheapest_fruit_no_loops(fruit_prices:dict) -> str:
    '''
    Find the cheapest fruit using min function. Do not use loops
    '''

    return min(fruit_prices, key=fruit_prices.get)

# grouping
def group_fruits(fruits:list):
    '''
    Group the fruits based on the first letter of the names. Assume first letters will be upper case.

    Arguments:
    fruits - list: list of fruit names

    Return:
    dict: dict with the first letters as keys and list of fruits sorted in ascending order as values.
    '''

    fruits_with_first_letter = {}
    for fruit in fruits:
        if fruit[0] not in fruits_with_first_letter:
            fruits_with_first_letter[fruit[0]] = []
        fruits_with_first_letter[fruit[0]].append(fruit)
    return {
      letter: sorted(fruits)
      for letter, fruits in fruits_with_first_letter.items()
    }

# binning
def bin_fruits(fruit_prices):
    '''
    Classify the fruits as cheap, affordable and costly based on the fruit prices. Create a dictionary with the classification as keys and a set of fruits in that category.

    cheap - less than 3 (not inclusive)
    affordable - between 3 and 6 (both inclusive)
    costly - greater than 6 (not inclusive)

    Arguments:
    fruit_prices: dict - dictionary with fruits as keys and prices as values

    Return:
    binned_fruits: dict - dictionary with category as key and a set of fruits in that category as values.
    '''

    binned_fruits = {category:set() for category in ["cheap","affordable","costly"]}
    for fruit, price in fruit_prices.items():
        if price<3:
            binned_fruits["cheap"].add(fruit)
        elif 3<=price<=6:
            binned_fruits["affordable"].add(fruit)
        else:
            binned_fruits["costly"].add(fruit)
    return binned_fruits