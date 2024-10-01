 public int bagOfTokensScore(int[] tokens, int power) {

        Arrays.sort(tokens);
        if (tokens.length == 0 || power < tokens[0]) return 0;

        int score = 0;
        int i = 0, j = tokens.length -1;
        while ( i <= j ) {
            if (tokens[i] <= power) {
                power -= tokens[i++];
                score++;
            } else if (i != j) {
                power += tokens[j--];
                score--; 
            } else i++;
        }
        return score;

    }