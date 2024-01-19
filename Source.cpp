//std-name: Saadet Elizaveta Babal

#include <iostream>//This line contains the input/output stream library and provides functionality to read and write from standard input/output streams. That's why I used it.
#include <string>//This line contains the string library and provides functions and classes for working with arrays. That's why I used it.
#include <vector>//Vector stores elements of a given type in a linear order and provides fast random access to any element. That's why I used it.
#include <ctime>//This line contains the ctime library, which provides functions for working with time and date. It is usually used for random number generation using the current time. That's why I used it.
#include <cstdlib>//This line contains the cstdlib library, which stands for "C Standard Library". It includes memory allocation, random number generation and other general purpose functions. I used it for this.
#include <algorithm>//This line contains the algorithm library, which contains functions to operate on a set of elements to perform various operations. It contains algorithms for sorting, searching, and manipulating elements in containers such as vector. That's why I added it.

using namespace std;//This line allows us to directly use names from the C++ standard library using the std (Standard) namespace. In this way, we can easily use standard elements such as cout, cin, string. That's why I added it.

namespace SynonymGame {//This line defines a namespace called SynonymGame. Namespaces are used to prevent name conflicts within a given scope and to keep the code more organized. That's why I used it.

    class Game {//This line defines a class called Game.
    private://This line indicates that the following private member variables will be defined within this class. Private means these members are only accessible within the class.
        vector<string> words;//This line defines a string vector named words. Vector stores elements of a particular type in a linear order and provides fast random access to these elements. This feature is useful for keeping data such as word lists.
        vector<string> synonyms;//This line defines another string vector called synonyms. This vector can also be used to hold synonyms. That's what I used for this.
        string currentWord;//These lines define string variables to store the current word and the current synonym respectively.
        string currentSynonym;//These lines define string variables to store the current word and the current synonym respectively.
        int maxGuesses;//These lines define integer variables to store the maximum number of guesses and the player's score respectively.
        int score;//These lines define integer variables to store the maximum number of guesses and the player's score respectively.

    public://Constructor of Game class that initializes member variables with provided values. That's why I used it.
        Game(const vector<string>& wordList, const vector<string>& synonymList, int max) : words(wordList), synonyms(synonymList), maxGuesses(max), score(0) {}
        // wordList: List of words for the game.
        // synonymList: List of synonyms corresponding to the words.
        // max: Maximum number of guesses allowed.
        // score: Initial score set to 0.
        static void DisplayGameInformation() {//I chose to use a static method to display game related information.This method is called on the class itself, not on an instance of the class, so I used it here.
            cout << "  -----------------------\n";
            cout << " |      Synonym Game     | \n";//I wrote this line to print the title of the game.
            cout << "  -----------------------\n";
            cout << "\n -Guess the synonym for the given word.\n";//I wrote these lines to indicate the rules of the game.
            cout << " -You have a limited number of guesses.\n\n";//I wrote these lines to indicate the rules of the game.
        }

        void StartGame() {//Here i start the game by setting up a random word and its synonym.
            srand(static_cast<unsigned int>(time(nullptr)));//Here i am making sure that the randomness of my game is unique by seeding it with the current time.
            int randomIndex = rand() % words.size();//Here i am randomly picking an index within the range of available words.
            currentWord = words[randomIndex];//Here i am assigning the selected word and its synonym based on the random index.
            currentSynonym = synonyms[randomIndex];

            cout << " Word: " << currentWord << "\n";// Here i am showing the player the word they need to work with.
            cout << " Your task is to guess the synonym for the word.\n";// I'm giving the player a hint about the game, explaining that they need to guess the synonym for the shown word.

            for (int i = 0; i < maxGuesses; i++) {// I'm starting a loop where the player can make guesses within a set number of attempts.
                string guess;
                cout << " Enter your guess: ";// I'm asking the player to input their guess.
                cin >> guess;

                if (guess == currentSynonym) {// I'm checking if the player's guess matches the actual synonym.
                    cout << " Correct guess!\n";  // If the guess is correct, I'm congratulating the player, updating their score, and ending the loop.
                    score += 100;
                    break;
                }
                else {
                    cout << " Incorrect guess. Try again.\n";// If the guess is incorrect, I'm letting the player know and prompting them to try again.
                }
            }

            cout << " The synonym for the word " << currentWord << " is " << currentSynonym << ".\n\n";// I'm revealing the correct synonym for the word I asked user to guess.

            string playAgain;
            cout << " Do you want to play again? (yes/no): ";// I'm asking if user up for another round of the game.
            cin >> playAgain;//Here I'm checking users response.

            if (playAgain == "yes") {// If user wants to play game for more,here i am starting a new round.
                StartGame();
            }
            else {
                cout << " Your final score is: " << score << "\n";//If the user wants to end the game, I say the final score here.
            }
        }
    };
}

namespace GuessMovieGame {//I'm setting up a namespace called GuessMovieGame to organize my game-related code.

    class Game {// Now, I'm defining the Game class.
    private:
        // These are my secret collections of movies categorized by difficulty.
        vector<string> easyMovies;
        vector<string> mediumMovies;
        vector<string> hardMovies;
        string selectedMovie;// The movie that the player needs to guess.
        string hiddenMovie; // A version of the movie with some characters hidden, to display during guessing.
        int score;// I'll keep track of the player's score here.

    public:// I'm defining the constructor for the Game class.
        // I'm initializing the movie collections for each difficulty level and setting up initial values.
        Game() : easyMovies{ "Source Code", "The Zodiac", "The Limitless", "In Time" },
            mediumMovies{ "Men In Black", "The Dark Knight", "I Am Legend", "The Shutter Island" },
            hardMovies{ "Night at the Museum","The Lord of the Rings", "The Pursuit of Happyness", "The Wizard of Oz" },
            selectedMovie(""), hiddenMovie(""), score(0) {}

        static void DisplayGameInformation() {// A static method to display information about the game.
            cout << "  ---------------------------\n";
            cout << " |      Movie Guess Game     |\n";// Displaying the title of the game.
            cout << "  ---------------------------\n";// Adding a visual separator.
            cout << "\n -Guess the name of the movie by revealing hidden letters.\n";// Providing instructions for the game.
            cout << " -You can guess individual letters or the entire movie name.\n\n";// Explaining the guessing options.
        }

        void StartGame(int difficulty) { // A method to start the game based on the chosen difficulty level.
            // I'm selecting the appropriate movie list based on the chosen difficulty level.
            vector<string>& movieList = (difficulty == 1) ? easyMovies : ((difficulty == 2) ? mediumMovies : hardMovies);
            selectedMovie = movieList[rand() % movieList.size()]; // I'm randomly selecting a movie from the chosen list.
            hiddenMovie = HideLetters(selectedMovie);// I'm creating a version of the movie with hidden letters for guessing.
            score = 0;// I'm resetting the player's score to zero for a fresh start.
        }

        string HideLetters(const string& movie) {// A function to create a version of the movie title with hidden letters.
            string hiddenMovie = movie;// I'm starting with the original movie title.
            for (char& c : hiddenMovie) {// For each character in the movie title:
                if (c != ' ') {// If it's not a space, I'm replacing it with an asterisk (*).
                    c = '*';
                }
            }
            return hiddenMovie;// I'm returning the modified movie title with hidden letters.
        }

        bool GuessLetter(char letter) {// A function to check if a guessed letter is present in the movie title.
            bool letterFound = false;// I'll keep track of whether the guessed letter is found in the movie title.
            for (int i = 0; i < selectedMovie.length(); i++) {// Loop through each character in the selected movie title.
                if (selectedMovie[i] == letter) { // If the guessed letter matches a character in the movie title:
                    hiddenMovie[i] = letter;// Reveal the letter in the hidden movie title.
                    letterFound = true;// Mark that the letter was found.
                    score += 100; // Increase the player's score.
                }
            }
            return letterFound;// Return whether the guessed letter was found in the movie title.
        }

        bool GuessMovieName(const string& movieName) {// A function to check if the guessed movie name matches the selected movie.
            // I'm comparing the guessed movie name with the actual selected movie.
            return movieName == selectedMovie;// If they match, it returns true; otherwise, it returns false.
        }

        void PrintGameState() {// A function to print the current state of the game.
            cout << " Hidden Movie: " << hiddenMovie << endl;// I'm displaying the version of the movie title with hidden letters.
            cout << " Score: " << score << "\n" << endl;// I'm showing the player's current score.
        }
    };
}

namespace MillionaireGame {// I'm creating a namespace named MillionaireGame to organize my game-related code.

    class Question {// I'm defining a class called Question to represent a quiz question.
    private:
        // These are private member variables to store the question text, correct answer, and a list of wrong answers.
        string questionText;
        string correctAnswer;
        vector<string> wrongAnswers;

    public:
        // Constructor to initialize the Question object with the provided question text, correct answer, and wrong answers.
        Question(const string& text, const string& correct, const vector<string>& wrongs)
            : questionText(text), correctAnswer(correct), wrongAnswers(wrongs) {}

        string getQuestionText() const { return questionText; }// Public method to retrieve the question text.

        string getCorrectAnswer() const { return correctAnswer; }// Public method to retrieve the correct answer.

        vector<string> getWrongAnswers() const { return wrongAnswers; }// Public method to retrieve the list of wrong answers.
    };

    class Game {// I'm extending the Game class to include vectors of questions for different difficulty levels.
    private:
        // These private member variables store vectors of questions for different difficulty levels.
        vector<Question> easyQuestions;//This line declares a vector named easyQuestions that can hold elements of type Question.This vector will be used to store easy-level questions.
        vector<Question> mediumQuestions;
        vector<Question> hardQuestions;
        vector<Question> veryHardQuestions;
        // Additional variables to keep track of the player's prize money and mistakes.
        int prizeMoney;
        int mistakes;

    public:
        // The constructor initializes prizeMoney and mistakes to 0 and populates question vectors for each difficulty level.
        Game() : prizeMoney(0), mistakes(0) {// I'm setting the initial prize money and mistakes to 0.
            // Now, I'm populating the question sets for each difficulty level.
            populateEasyQuestions();
            populateMediumQuestions();
            populateHardQuestions();
            populateVeryHardQuestions();
        }

        static void DisplayGameInformation() {// Static method to display information about the game.
            // I'm providing a brief overview of the game rules and mechanics.
            cout << "  -----------------------------------------\n";
            cout << " |      Who Wants to Be a Millionaire      | \n";
            cout << "  -----------------------------------------\n";
            cout << "\n -Answer multiple-choice questions to win increasing amounts of money.\n";
            cout << " -You have three lives. If you get more than 3 wrong answers, the game ends.\n\n";
        }

        void populateEasyQuestions() {// Member function to populate the easyQuestions vector with predefined questions.
            easyQuestions = {// I'm filling the easyQuestions vector with a set of my predefined questions and their correct/incorrect answers.
                {" What is the capital of France?", "Paris", {"London", "Berlin", "Rome"}},
                {" What is the largest planet in our solar system?", "Jupiter", {"Mars", "Saturn", "Neptune"}},
                {" What is the chemical symbol for gold?", "Au", {"Ag", "Cu", "Fe"}},
                {" What is the largest ocean on Earth?", "Pacific Ocean", {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}},
                {" What is the square root of 64?", "8", {"4", "16", "32"}}
            };
        }

        void populateMediumQuestions() {// Member function to populate the mediumQuestions vector with predefined questions.
            mediumQuestions = {// I'm filling the mediumQuestions vector with a set of predefined questions and their correct/incorrect answers.
                {" Who painted the Mona Lisa?", "Leonardo da Vinci", {"Pablo Picasso", "Vincent van Gogh", "Michelangelo"}},
                {" What is the largest organ in the human body?", "Skin", {"Heart", "Liver", "Brain"}},
                {" What is the chemical symbol for sodium?", "Na", {"K", "Ca", "Mg"}},
                {" What is the capital of Australia?", "Canberra", {"Sydney", "Melbourne", "Perth"}},
                {" What is the boiling point of water in degrees Celsius?", "100", {"0", "50", "200"}}
            };
        }

        void populateHardQuestions() {// Member function to populate the hardQuestions vector with predefined questions.
            hardQuestions = {// I'm filling the hardQuestions vector with a set of predefined questions and their correct/incorrect answers.
                {" Who wrote the novel 'Pride and Prejudice'?", "Jane Austen", {"Charles Dickens", "Mark Twain", "William Shakespeare"}},
                {" What is the largest bone in the human body?", "Femur", {"Skull", "Tibia", "Humerus"}},
                {" What is the chemical symbol for potassium?", "K", {"Na", "Ca", "Mg"}},
                {" What is the capital of Brazil?", "Brasilia", {"Rio de Janeiro", "Sao Paulo", "Salvador"}},
                {" What is the freezing point of water in degrees Celsius?", "0", {"-10", "10", "20"}}
            };
        }

        void populateVeryHardQuestions() {// Member function to populate the veryHardQuestions vector with challenging questions.
            veryHardQuestions = {// I'm filling the veryHardQuestions vector with a set of advanced questions and their correct/incorrect answers.
                {" Who discovered penicillin?", "Alexander Fleming", {"Marie Curie", "Albert Einstein", "Isaac Newton"}},
                {" What is the largest desert in the world?", "Sahara Desert", {"Gobi Desert", "Arabian Desert", "Antarctic Desert"}},
                {" What is the chemical symbol for silver?", "Ag", {"Au", "Cu", "Fe"}},
                {" What is the capital of Canada?", "Ottawa", {"Toronto", "Vancouver", "Montreal"}},
                {" What is the speed of light in meters per second?", "299,792,458", {"100,000", "1,000,000", "10,000,000"}}
            };
        }

        void shuffleQuestions(vector<Question>& questions) {// Member function to shuffle the order of questions.
            random_shuffle(questions.begin(), questions.end());// I'm using the random_shuffle function to shuffle the order of questions.
        }

        void startGame() {// Member function to start the game.
            // I'm shuffling the order of questions for each difficulty level.
            shuffleQuestions(easyQuestions);
            shuffleQuestions(mediumQuestions);
            shuffleQuestions(hardQuestions);
            shuffleQuestions(veryHardQuestions);

            // I'm asking questions for each difficulty level and displaying the difficulty.
            askQuestions(easyQuestions, "Easy");
            askQuestions(mediumQuestions, "Medium");
            askQuestions(hardQuestions, "Hard");
            askQuestions(veryHardQuestions, "Very Hard");

            cout << " Congratulations! You won $" << prizeMoney << "!\n";// I'm congratulating the player on their total prize money.
        }

        void askQuestions(vector<Question>& questions, const string& category) {// Here this function orchestrates the interaction with the player, presenting a set of questions based on their chosen category.
            cout << " Category: " << category << "\n";// Here i inform the player about the category of questions they are about to encounter.

            for (const Question& question : questions) {// Here i iterate through each question in the provided vector.
                cout << question.getQuestionText() << "\n";// Here i display the text of the current question.
                vector<string> answers = question.getWrongAnswers();// Here i generate a set of answers, including both correct and incorrect options, and shuffle them for variety.
                answers.push_back(question.getCorrectAnswer());//The purpose of this line is to add the correct answer to the answers vector. 
                //The push_back function is used to add a new element to the end of a vector. In this case, we add the correct answer to the answers vector.
                //The question.getCorrectAnswer() statement retrieves the correct answer from within the question object.
                //This answer represents the real answer to the question.This correct answer is then added to the answers vector with the push_back function.
                //This is done to show answers in a mixed orderand answer the question properly to the user.If we only include the correct answer, the answers may appear in the same order each time, making the game predictable.
                //Therefore, showing the correct answer in mixed order is important to make the game more interesting and challenging.
                random_shuffle(answers.begin(), answers.end());

                for (int i = 0; i < answers.size(); i++) {// Here i present the shuffled answers with corresponding numerical labels.
                    cout << " " << i + 1 << ". " << answers[i] << "\n";
                }

                int userAnswer;
                cout << " Enter your answer (1-" << answers.size() << "): ";// Heere i prompt the player to select their answer.
                cin >> userAnswer;

                if (answers[userAnswer - 1] == question.getCorrectAnswer()) {// Here i check the correctness of the chosen answer and adjust the game state accordingly.
                    cout << " Correct answer! You won $" << prizeMoney << "!\n\n";//This part retrieves the user's selected answer from the answers vector. The userAnswer variable contains the user's input, likely a number representing their choice. 
                    //The - 1 is used because vector indices start from 0, and user choices are usually provided as 1-based.
                    prizeMoney += 100; //Here i increase the prize money for a correct answer.
                }
                else {
                    cout << " Wrong answer!\n\n";
                    mistakes++; // Increment the mistake count for an incorrect answer.

                    if (mistakes >= 3) {// Here i check if the player has made three mistakes, and end the game if so.
                        cout << " You made 3 mistakes. Game over.\n";
                        return;
                    }
                }
            }
        }
    };
}

void DisplayMenu() {//Here DisplayMenu function shows a menu of available games for the user to choose from.
    cout << "\n ----------------------------------------------\n";
    cout << " |           Choose a game to play:           |\n";// Prompt the user to choose a game.
    cout << " |              1. Synonym Game               |\n";//Here i display the menu options with corresponding numbers for each game.
    cout << " |            2. Movie Guess Game             |\n";
    cout << " |      3. Who Wants to Be a Millionaire      |\n";
    cout << " ----------------------------------------------\n\n";
}

void DisplayGameIntroduction(int choice) {//Here DisplayGameIntroduction function takes the user's game choice and shows information about the selected game.
    switch (choice) {//I used a switch statement to determine which game was chosen based on the user's input.
    case 1:// If the user chose 1, display information about the Synonym Game.
        SynonymGame::Game::DisplayGameInformation();
        break;
    case 2:// If the user chose 2, display information about the Movie Guess Game.
        GuessMovieGame::Game::DisplayGameInformation();
        break;
    case 3:// If the user chose 3, display information about Who Wants to Be a Millionaire.
        MillionaireGame::Game::DisplayGameInformation();
        break;
    }
}

int main() { //Here is the main function where the program execution starts.
    string playerName, playerSurname, playAgain;// Here i declared variables to store player information and the playAgain choice.

    cout << " Enter your name: ";// Prompt the user to enter their name and surname.
    cin >> playerName;
    cout << " Enter your surname: ";
    cin >> playerSurname;
    cout << " Welcome, " << playerName << " " << playerSurname << "!\n";// Welcome the player by their full name.

    srand(static_cast<unsigned int>(time(nullptr)));//This line ensures that the program gets a different starting point for its random number generation each time it is run, contributing to a more varied and less predictable sequence of random numbers.
    //This part seeds the random number generator rand with the converted current time.
    do {// Here i started a loop to allow the player to choose and play multiple games.
        DisplayMenu();// Displayed the game menu for the player to choose from.
        cout << " Enter the game number: ";
        int choice;// Declared a variable to store the user's game choice.
        cin >> choice;// Got the user's choice for the game.

        DisplayGameIntroduction(choice);// Displayed an introduction to the selected game.

        switch (choice) {
        case 1: {// Created vectors containing words and their synonyms.
            vector<string> words = { "fast", "beautiful","happy", "big", "small","bad","good","easy","cold" };
            vector<string> synonyms = { "quick", "gorgeous","joyful", "large", "tiny","awful","fine","simple","chilly" };
            SynonymGame::Game game(words, synonyms, 9);// Created an instance of the SynonymGame::Game class and started the game.
            game.StartGame();//Class with these vectors and a maximum number of guesses (9).
            break;
        }
        case 2: {
            GuessMovieGame::Game game;// Created an instance of the GuessMovieGame::Game class.
            int difficulty;
            cout << " Choose the difficulty level (1 for easy, 2 for medium, 3 for hard): ";// Prompted the user to choose the difficulty level.
            cin >> difficulty;
            game.StartGame(difficulty);// Called the StartGame method of the GuessMovieGame::Game class with the chosen difficulty.

            int option;
            while (true) {// Here displayed the current state of the game, including hidden movie name and score.
                game.PrintGameState();
                cout << " Choose an option:\n";// Here i displayed the menu of options for the player to choose from.
                cout << " 1. Guess a letter\n";
                cout << " 2. Guess the movie name\n";
                cout << " 3. Exit\n";
                cout << " Enter the number: ";
                cin >> option;

                if (option == 1) {// Handled the player's choice based on the selected option.
                    char letter;// If the player chooses to guess a letter:
                    cout << "\n Enter a letter: ";
                    cin >> letter;

                    bool letterFound = game.GuessLetter(letter);// Make a guess for the letter and display the result.
                    cout << (letterFound ? "\n Letter found!\n" : " Letter not found.\n");
                }
                else if (option == 2) {// If the player chooses to guess the entire movie name:
                    string movieName;
                    cout << "\n Enter the movie name: ";
                    cin.ignore();// Ignore any previous newline characters in the input buffer.
                    getline(cin, movieName);

                    bool correctGuess = game.GuessMovieName(movieName);// Make a guess for the movie name and display the result.
                    cout << (correctGuess ? " Congratulations! You guessed the movie correctly.\n" : " Incorrect guess.\n");

                    if (correctGuess) break;
                }
                else if (option == 3) {// If the player chooses to exit the game, exit the loop.
                    break;
                }
                else {// If the user's choice is not 1,2 or 3 this code block works.
                    cout << " Invalid option. Please choose again.\n";
                }
            }
            break;
        }
        case 3: {// If the user chooses option 3 (Who Wants to Be a Millionaire game) works.
            MillionaireGame::Game game;
            game.startGame();
            break;
        }
        default:// If the user's choice doesn't match any case this block works.
            cout << " Invalid choice. Exiting.\n";
            break; //Here if the user enters an option other than 1, 2, or 3, it prints an error message and breaks out of the switch statement.
        }

        cout << " Do you want to play another game? (yes/no): ";//This line prompts the user if they want to play another game. 
        cin >> playAgain;//The user's response is stored in the playAgain variable.

    } while (playAgain == "yes"); //This loop allows the player to chooseand play different games.

    cout << " Thanks for playing! Goodbye.\n"; //Here when the player decides not to play another game, it prints a farewell message.

    return 0;//Here the main function ends, and the program returns 0.
}
