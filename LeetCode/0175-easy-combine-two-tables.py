import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    data = {
        'firstName': [],
        'lastName': [],
        'city': [],
        'state': []
    }
    for person_id in person['personId'].values:
        A = person[person['personId'] == person_id]['firstName'].values
        B = person[person['personId'] == person_id]['lastName'].values
        C = address[address['personId'] == person_id]['city'].values
        D = address[address['personId'] == person_id]['state'].values

        data['firstName'].append(A[0] if len(A) > 0 else None)
        data['lastName'].append(B[0] if len(B) > 0 else None)
        data['city'].append(C[0] if len(C) > 0 else None)
        data['state'].append(D[0] if len(D) > 0 else None)
    return pd.DataFrame(data)
