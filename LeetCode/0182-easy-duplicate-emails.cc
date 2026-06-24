import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    dupes = { 'Email': [] }
    emap = set()
    emap2 = set()
    for i, row in person.iterrows():
        eid = row['id']
        email = row['email']
        if email in emap and not email in emap2:
            dupes['Email'].append(email)
            emap2.add(email)
        else:
            emap.add(email)
    return pd.DataFrame(dupes)
