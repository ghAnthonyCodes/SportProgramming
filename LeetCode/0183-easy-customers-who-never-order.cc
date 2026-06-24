import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    customer_set = set(customers['id'].values)
    cmap = { }
    for i, row in customers.iterrows():
        cmap[row['id']] = row['name']
    for i, row in orders.iterrows():
        customer_id = row['customerId']
        customer_set.discard(customer_id)
    return pd.DataFrame({ 'Customers': [cmap[x] for x in customer_set] })
    
