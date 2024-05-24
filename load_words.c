Word *load_words(const char *filepath, int *n_words) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        perror("Cannot open file");
        return NULL;
    }

    Word *words = NULL;
    *n_words = 0;

    char *line;
    while ((line = read_a_line(fp)) != NULL) {
        words = realloc(words, (*n_words + 1) * sizeof(Word));
        words[*n_words].word = strtok(line, "\"");
        strtok(NULL, "\"");
        words[*n_words].meaning = strtok(NULL, "\"");
        (*n_words)++;
    }

    fclose(fp);
    return words;
}