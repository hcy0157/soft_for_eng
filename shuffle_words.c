void shuffle_words(Word *words, int n_words) {
    for (int i = 0; i < n_words; i++) {
        int j = rand() % n_words;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}