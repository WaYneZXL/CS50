# Movie Revenue Forecast Tool
#### by Shijing Liu, Victor Zhu, and Xiaolong Zhu

## Comments:
- Our project utilizes machine learning techniques to forecast predicted revenue based on inputs given by the users.
- Our team decided to use linear regression and random forest algorithm to forecast revenue as they offer the best predictibility compared with the other algorithms we tested (shown in Appendix)
- Our final output is a .ipynb file, to be executed in Jupyter notebook.


## Our Notebook is organized as follow:
1. Clean and organize the movies and credits dataset and train our data with the required information (Run time 3~4 minutes)
2. Enter user inputs (budget, runtime, movie director, actor, key words) through our interactive widgets to allow our algoritm to recalibrate
3. Retrieve user inputs in step 2 and implement random forest and linear model to generate final outputs


## User manual:
- Step 1: download the raw data file. `tmdb_5000_credits.csv` and `tmdb_5000_moviess.csv` are required. User should download both databases and update the downloaded files' directory here:
```
movies = load_tmdb_movies("../Desktop/tmdb_5000_movies.csv")
credits = load_tmdb_credits("../Desktop/tmdb_5000_credits.csv")
```
- Step 2: user should run the "Final CS50 Project.ipynb" file in Jupyter Notebook environment (run as Python 3)
- Step 3: user should run the "Step 1: Clean and train the dataset" part first to clean data and train the model, which may take 3-4 minutes running time
- Step 4: user should run the Step 2 codes and then input key variables (e.g. movie genra, runtime, director, actors, studio etc.) in the interactive area based on their own preference (or project)
- Step 5: user should run the Step 3 codes and the prediction result would be presented

## YouTube link
https://youtu.be/HqgZydFepZE

