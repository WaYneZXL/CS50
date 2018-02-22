# Movie Revenue Forecast Tool
#### by Shijing Liu, Victor Zhu, and Xiaolong Zhu

## Database selection
We chose to use the tmdb (The Movie Database: https://www.themoviedb.org/en) database for a few reasons:
- TMDB's data was free to use while IMDB requires an AWS S3 account to fetch data, which none of us has.
- TMDB's APIs were more intruitive and user-friendly and data is ready to use (i.e. movie revenues and budgets were converted to USD while IMDB's data are in local currency)
- TMDB data requires additional work to process and clean (details as following)

## Data clean up
- We conducted a series basic clean-up exercise, e.g. taking out empty data, taking out json that nested in the original dataset, cleaned up all naming issues etc.
- We have pivoted all categorical data into numarical data from the original database in order to run the algorithm
- We have set the data into seperate training data and testing set in order to validate the accuracy and choose the best algorithm
- We have tested multiple ways of data format and setup, in the end we've decided to seperate the directors and actors into 5 groups and seperate the studios into 2 groups so the dataset contains only 50-60 columns instead of hundreds

## Machine Leatning Algorithms
- We used six commonly used Machine Learning algorithms for our supervised learning: "Linear Regression","Logistic Regression","Random Forest","Support Vector Machine","Naive Bayes","Decision Tree". Result comparison is in the appendix of our notebook.
- Eventually we used Linear Regression and Random Forest as both delivered roughly 70% accuracy

## Why use Python?
- We've decided to use Python given its easiness to deal with large amount of data and we understand Python is one of the mostly used language in the data scientist community nowadays
- From our research, we also found there are open source library (sklearn, which is the prodominant library/tool used by the data scientist community nowadays) using Python that allowed us to apply the variours Machine Learning to the dataset
- We chose Python also based on our learning goals - three of us were hoping to learn more about how to deal with data analysis using Python

## Why Jupyter / not IDE?
- We started building all the code through Jupyter platform, which allows us to test code line by line and figure out the issues quickly
- We have tried to move and mimplement the project on IDE and build a corresponding website after we've finalized the algorithms on Jupyter
- However, there are technical challenges that beyond our ability - few libraries are not fully supported by flask (esp. tkinter), and we were not able to run flask successfully to launch the interactive user website
- In the end, we figured out ways to build an interactive section on Jupyter via ipython to allow users provide their inputs and generate forecast accordingly

## Potential plans going forward?
- If there are more time allowed, we'd like to introduce more data columns into the algorithm to further improve the accuracy
- We could also play more with the raw dataset from the data cleaning perspective to make it suit better with other algorithms that currently are not generating satisfactory results
- We could also improve the user interactive platform, if we could fix the technical challenge on IDE, we could potentially also build a website to take user inputs and feedback results