 LexiFix: Real-Time Spell-Checking Application

LexiFix is a C++-based real-time spell-checking application that uses advanced algorithms for efficient and accurate typo detection and correction. It integrates the Damerau-Levenshtein distance and n-gram modeling to suggest context-aware corrections for misspelled words.

 🌟 Key Features
- Real-Time Spell Correction: Instantly detects and corrects typos with high accuracy.
- Advanced Algorithms: Utilizes Damerau-Levenshtein and n-gram models for error detection and contextual suggestions.
- Efficient Design: Optimized for performance with minimal resource consumption.

## 🛠 Technologies Used
- **C++**
- **Damerau-Levenshtein Algorithm**
- **N-gram Modeling**

## 🧩 Project Components
1. **Core Spell Checker**: Detects and corrects typos using the Damerau-Levenshtein algorithm.
2. **N-gram Model**: Enhances suggestion accuracy by analyzing word probabilities in context.

## 💡 How It Works
1. **Input Text**: Users provide text for analysis.
2. **Error Detection**: The system identifies typos using Damerau-Levenshtein distance.
3. **Suggestions**: Generates corrections using n-gram probabilities for context-aware suggestions.

## 📂 Project Structure
```
/LexiFix
│
├── /src                # Source files
│   ├── main.cpp        # Main program
│   ├── spellcheck.cpp  # Spell-checking logic
│   └── ngram.cpp       # N-gram modeling
│
├── /include            # Header files
│   └── spellcheck.h    # Header for spell-checking logic
│
├── /data               # Dataset or dictionary
│   └── dictionary.txt  # Word dictionary for corrections
│
└── README.md           # Project documentation
```

## 🚀 How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/LexiFix.git
   ```

2. Navigate to the project folder:
   ```bash
   cd LexiFix
   ```

3. Compile the code:
   ```bash
   g++ -o lexifix src/main.cpp src/spellcheck.cpp src/ngram.cpp
   ```

4. Run the program:
   ```bash
   ./lexifix
   ```

5. Enter text to check for spelling errors.

## 💬 Contributing

Feel free to open an issue or submit a pull request if you want to contribute to this project.

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```




