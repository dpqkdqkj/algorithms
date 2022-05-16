class CaesarCipher(object):
    def __init__(self, shift):
        self.shift = shift
        self.alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        self.tableOrd = dict(zip(self.alphabet, range(len(self.alphabet))))
        self.tableChr = dict(zip(range(len(self.alphabet)), self.alphabet))

    def encode(self, st):
        return self._shift_st(st.upper(), self.shift)

    def decode(self, st):
        return self._shift_st(st, -self.shift)

    def _shift_st(self, st, shift):
        res = ""
        for char in st:
            if char in self.alphabet:
                res += self.tableChr[(self.tableOrd[char] + shift) % 26]
            else:
                res += char
        return res
