# Only hard here !

https://leetcode.com/problems/palindrome-pairs/description/
## solved
KMP
kmp 数组的是什么：
    he Naive pattern searching algorithm doesn’t work well in cases where we see many matching characters followed by a mismatching character

whenever we detect a mismatch (after some matches), we already know some of the characters in the text of next window. We take advantage of this information to avoid matching the characters that we know will anyway match. Let us consider below example to understand this.

A proper prefix is prefix with whole string not allowed


lps[i] = the longest proper prefix of pat[0..i] 
        which is also a suffix of pat[0..i]. 

1. algorithm
We start comparison of pat[j] with j = 0 with characters of current window of text.
We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
When we see a mismatch
    We know that characters pat[0..j-1] match with txt[i-j+1…i-1] (Note that j starts with 0 and increment it only when there is a match).

    We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.

    From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match. Let us consider above example to understand this.
```
 algorithm kmp_table:
    input:
        an array of characters, W (the word to be analyzed)
        an array of integers, T (the table to be filled)
    output:
        nothing (but during operation, it populates the table)

    define variables:
        an integer, pos ← 1 (the current position we are computing in T)
        an integer, cnd ← 0 (the zero-based index in W of the next character of the current candidate substring)

    let T[0] ← -1

    while pos < length(W) do
        if W[pos] = W[cnd] then
            let T[pos] ← T[cnd], pos ← pos + 1, cnd ← cnd + 1
        else
            let T[pos] ← cnd

            let cnd ← T[cnd] (to increase performance)

            while cnd >= 0 and W[pos] <> W[cnd] do
                let cnd ← T[cnd]

            let pos ← pos + 1, cnd ← cnd + 1

    let T[pos] ← cnd (only need when all word occurrences searched)
```

