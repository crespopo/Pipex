#include "libft/libft.h"

//Counts the number of words of s string adding one everytime it finds
// something different than c (delimitator). But it takes into the account
// the flag to accept c into the word.
static size_t	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			counter++;
			if (s[i] == '\'')
				flag = 1;
			while ((s[i] && s[i] != c) || flag == 1)
			{
				i++;
				if (s[i] == '\'')
					flag = 0;
			}
		}
	}
	return (counter);
}

//Copy the word in the allocated memory. If the word is between ' ' it
//doesn't copy the ''.
static char	*copy_word(char const *s, int i, char *word, size_t word_len)
{
	int	j;

	j = 0;
	if (s[i - 1] == '\'')
		i -= 1;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

//Calculates de length of the next word in s starting in i position.
//It accepts c as part of the word if spc_allowed is 1.
//It returns the calculated length. It doesn't count '' in length.
//example to follow: "cut -d ' ' -f 3,1"
static size_t	calc_word_len(char const *s, char c, int *i)
{
	size_t	word_len;
	int		spc_allowed;

	word_len = 0;
	spc_allowed = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	if (s[*i] == '\'')
		spc_allowed = 1;
	while ((s[*i] && s[*i] != c) || spc_allowed)
	{
		if (s[*i] != '\'')
			word_len++;
		(*i)++;
		if (s[*i] == '\'')
			spc_allowed = 0;
	}
	return (word_len);
}

static char	**fill_words(char const *s, char c, char **words, size_t num_words)
{
	size_t	word_len;
	int		i;
	size_t	word;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		word_len = calc_word_len(s, c, &i);
		words[word] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!words[word])
			return (free_array_split(words, word));
		words[word] = copy_word(s, i, words[word], word_len);
		word++;
		word_len = 0;
	}
	return (words);
}

/*Allocate (with malloc) and returns an array of strings obtained
by splitting s with the character c, used as delimiter.
The difference with ft_split is that if a ' appears it doesn´t
take into account de delimeter till another ' appears*/
char	**ft_split_squotes(char const *s, char c)
{
	char	**words;
	size_t	num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	words = (char **)ft_calloc((num_words + 1), sizeof(char *));
	if (!words)
		return (NULL);
	words = fill_words(s, c, words, num_words);
	return (words);
}
