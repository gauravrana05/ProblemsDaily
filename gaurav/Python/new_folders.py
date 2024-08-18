import os
import logging

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

def create_week_folders(n_weeks, m_files):
    for week in range(1, n_weeks + 1):
        folder_name = f"Week_{week}"
        
        try:
            # Create the folder if it doesn't exist
            if not os.path.exists(folder_name):
                os.makedirs(folder_name)
                logging.info(f"Created folder: {folder_name}")
            else:
                logging.info(f"Folder already exists: {folder_name}")

            for file_num in range(1, m_files + 1):
                file_name = f"GrPA{file_num}.py"
                file_path = os.path.join(folder_name, file_name)
                
                # Create the file if it doesn't exist
                if not os.path.exists(file_path):
                    with open(file_path, 'w') as f:
                        f.write(f"# {file_name} for {folder_name}")
                    logging.info(f"Created file: {file_path}")
                else:
                    logging.info(f"File already exists: {file_path}")

        except OSError as e:
            logging.error(f"Error creating folder or file: {e}")
        except Exception as e:
            logging.error(f"An unexpected error occurred: {e}")

# Example usage:
n_weeks = 11  # Number of weeks
m_files = 5  # Number of files per week

create_week_folders(n_weeks, m_files)
