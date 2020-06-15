
template<typename T>
bool Hash_Table<T>::processing(T str) {
    bool inserted = false;
    for ( char a : str ) {
        if ( isalpha(a) ) {
            int hsh = hash( tolower(a) );
            letters[ hsh ].letter = tolower(a);
            letters[ hsh ].count++;
            inserted = true;
        }
    }
    return inserted;
}

template<typename T>
void Hash_Table<T>::print() const {
    for (int i = 0; i < size; i++) {
        if (letters[i].count)
            std::cout << letters[i].letter << " " << letters[i].count << std::endl;
    }
}

template<typename T>
void Hash_Table<T>::search(char a) {
    int hsh = hash(a);
    std::cout << letters[ hsh ].letter << " " << letters[ hsh ].count << std::endl;
}