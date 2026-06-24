import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    manager_map = { }
    for i, row in employee.iterrows():
        manager_map[int(row['id'])] = row['salary']

    answer_dict = {
        'Employee': []
    }
    for i, row in employee.iterrows():
        e_id = row['id']
        e_name = row['name']
        m_id = row['managerId']
        print(m_id)
        if str(m_id) == '<NA>': continue 
        e_salary = row['salary']
        if m_id in manager_map:
            m_salary = manager_map[m_id]
            if m_salary < e_salary:
                answer_dict['Employee'].append(e_name)

    return pd.DataFrame(answer_dict)
