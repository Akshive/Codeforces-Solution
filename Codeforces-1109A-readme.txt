We need to find pairs(l, r) such that a(l)^a(l+1)^....^a(mid) = a(mid+1)^.....a(r) if r-l+1 is even that means number of elements are even.

We know that a^b^c^d^e = f implies a^b^c^d^e^f = 0 and a^b^c = d^e^f (Only for even number of elements), So we need to find number of
pairs(l, r) such that xor(l, r) == 0 and r-l+1 == even.

if xor(l, r) == 0 then xor(0, r) = xor(0, l-1), to find such we can maintain an _xor array(given in code), now how to find whether r-l+1
is even or not, r-l+1 is even if one is even and other is odd therefore we have maintained it using odd and even arrays.

