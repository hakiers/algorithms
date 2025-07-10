# 📌 Partition Function

The **partition function** represents the number of possible ways to partition a non-negative integer **n** into sums of positive integers.  
It can be computed in **O(n√n)** time complexity.


To compute the number of partitions, we use a **generating function**.

---

## 📐 Generating Function for the Partition Function

Let **P(x)** be the generating function for the partition function:


!['''math
P(x) = \sum_{n=0}^{\infty} p(n) \cdot x^n  
= \frac{1}{\prod_{k=1}^{\infty} (1 - x^k)}
'''](https://latex.codecogs.com/png.latex?\color{white}{P(x)%20=%20\sum_{n=0}^{\infty}%20p(n)%20\cdot%20x^n=%20\frac{1}{\prod_{k=1}^{\infty}%20(1%20-%20x^k)}})

Where:
- `p(n)` is the number of partitions of `n`
- The product runs over all positive integers

We also define:

!['''math
Q(x) = P(x)^{-1}
= \prod_{k=1}^{\infty} (1 - x^k)
'''](https://latex.codecogs.com/png.latex?\color{white}{Q(x)%20=%20P(x)^{-1}=%20\prod_{k=1}^{\infty}%20(1%20-%20x^k)})

It follows that:

!['''math
P(x) \cdot Q(x) = 1
'''](https://latex.codecogs.com/png.latex?\color{white}{P(x)%20\cdot%20Q(x)%20=%201})

---

## 📊 Special Partition Sets

Let:
- **Eₙ** be the set of partitions of the integer **n** into an **even number of parts, with all parts pairwise distinct**
- **Oₙ** be the set of partitions of the integer **n** into an **odd number of parts, with all parts pairwise distinct**

Then:
- `eₙ = |Eₙ|` — the number of such even-part partitions
- `oₙ = |Oₙ|` — the number of such odd-part partitions

---

## 📏 Generating Functions for `eₙ` and `oₙ`

The generating function for `eₙ + oₙ` has the form:

!['''math
\prod_{k=1}^{\infty} (1 + x^k)
'''](https://latex.codecogs.com/png.latex?\color{white}{\prod_{k=1}^{\infty}%20(1%20+%20x^k)})

And the generating function for `eₙ - oₙ` is:

!['''math
\prod_{k=1}^{\infty} (1 - x^k) = Q(x)
'''](https://latex.codecogs.com/png.latex?\color{white}{\prod_{k=1}^{\infty}%20(1%20-%20x^k)%20=%20Q(x)})

---

## 📖 Euler’s Pentagonal Number Theorem

Let’s define:

!['''math
q_n = e_n - o_n
'''](https://latex.codecogs.com/png.latex?\color{white}{q_n%20=%20e_n%20-%20o_n})

Then, according to **Euler’s theorem**:

!['''math
q_n =
\begin{cases}
(-1)^k & \text{if } n = \frac{3k^2 \pm k}{2} \text{ for integer } k \\
0 & \text{otherwise}
\end{cases}
'''](https://latex.codecogs.com/png.latex?\color{white}{q_n%20=\begin{cases}(-1)^k%20&%20\text{if%20}%20n%20=%20\frac{(3k%20\pm%201)k}{2}%20\text{%20for%20integer%20}%20k%20\\0%20&%20\text{otherwise}\end{cases}})

Meaning that among the numbers:

!['''math
q_0, q_1, q_2, \dots, q_n
'''](https://latex.codecogs.com/png.latex?\color{white}{q_0,%20q_1,%20q_2,%20\dots,%20q_n})

only **O(√n)** values are non-zero.

The generating function for `qₙ` is:

!['''math
Q(x) = \sum_{n=0}^{\infty} q_n \cdot x^n
'''](https://latex.codecogs.com/png.latex?\color{white}{Q(x)%20=%20\sum_{n=0}^{\infty}%20q_n%20\cdot%20x^n})

---

## 🔄 Relation Between `p(n)` and `qₙ`

Since:

!['''math
P(x) \cdot Q(x) = 1
'''](https://latex.codecogs.com/png.latex?\color{white}{P(x)%20\cdot%20Q(x)%20=%201})


We have:

![
'''math
\left(\sum_{n=0}^{\infty} p(n) \cdot x^n\right)
\cdot
\left(\sum_{n=0}^{\infty} q_n \cdot x^n\right)
= 1
'''](https://latex.codecogs.com/png.latex?\color{white}{\left%28\sum_{n=0}^{\infty}%20p%28n%29%20\cdot%20x^n\right%29\cdot\left%28\sum_{n=0}^{\infty}%20q_n%20\cdot%20x^n\right%29%3D1})

By multiplying and comparing coefficients:

!['''math
\sum_{k=0}^{n} p(k) \cdot q_{n-k} =
\begin{cases}
1 & \text{if } n = 0 \\
0 & \text{if } n > 0
\end{cases}
'''](https://latex.codecogs.com/png.latex?\color{white}{\sum_{k=0}^{n}%20p(k)%20\cdot%20q_{n-k}%20=\begin{cases}1%20&%20\text{if%20}%20n%20=%200%20\\0%20&%20\text{if%20}%20n%20>%200\end{cases}})

![test](https://latex.codecogs.com/png.latex?\color{white}%20%5Csum_%7Bk%3D0%7D%5E%7Bn%7D%20p(k)%20%5Ccdot%20q_%7Bn-k%7D%20%3D%20%5Cbegin%7Bcases%7D%201%20%26%20%5Ctext%7Bif%20%7D%20n%20%3D%200%20%5C%5C%200%20%26%20%5Ctext%7Bif%20%7D%20n%20%3E%200%20%5Cend%7Bcases%7D)

So for `n > 0`:

!['''math
p(n) = -\sum_{k=0}^{n-1} p(k) \cdot q_{n-k}
'''](https://latex.codecogs.com/png.latex?\color{white}{p(n)%20=%20-\sum_{k=0}^{n-1}%20p(k)%20\cdot%20q_{n-k}})

This recurrence allows efficient computation of `p(n)` using known values of `p(k)` and `qₘ`.

---

## ✅ Summary

- Partition numbers can be computed via generating functions.
- Euler’s pentagonal number theorem gives a sparse recurrence for `p(n)`.
- The generating function `Q(x)` encodes differences of partitions into even and odd numbers of distinct parts.
- The time complexity of the algorithm using this recurrence is **O(n√n)**.
