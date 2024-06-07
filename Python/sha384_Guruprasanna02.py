#// AUTHOR: Guruprasanna
#// Python3 Concept: sha384(hashing)
#// GITHUB: https://github.com/Guruprasanna02

#// Add your python3 concept below

#SHA384 hashing implementation manaually.



def rightrotate_64(i, j):
    i &= 0xFFFFFFFFFFFFFFFF
    return ((i >> j) | (i << (64 - j))) & 0xFFFFFFFFFFFFFFFF

def leftrotate_64(i, j):
    i &= 0xFFFFFFFFFFFFFFFF
    return ((i << j) | (i >> (64 - j))) & 0xFFFFFFFFFFFFFFFF

def leftshift(i, j):
    return i << j

def rightshift(i, j):
    return i >> j

class SHA384():
    def __init__(self):
        self.digest_size = 48
        self.block_size  = 96

        h0 = 0xcbbb9d5dc1059ed8
        h1 = 0x629a292a367cd507
        h2 = 0x9159015a3070dd17
        h3 = 0x152fecd8f70e5939
        h4 = 0x67332667ffc00b31
        h5 = 0x8eb44a8768581511
        h6 = 0xdb0c2e0d64f98fa7
        h7 = 0x47b5481dbefa4fa4

        self.k = [
            0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538, 
            0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe, 
            0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 
            0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 
            0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab, 
            0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725, 
            0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 
            0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b, 
            0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218, 
            0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 
            0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 
            0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec, 
            0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c, 
            0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6, 
            0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 
            0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
        ]

        self.hash_pieces = [h0, h1, h2, h3, h4, h5, h6, h7]
    
    def update(self, arg):
        h0, h1, h2, h3, h4, h5, h6, h7 = self.hash_pieces
        data = bytearray(arg)
        orig_len_in_bits = (8 * len(data)) & 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        data.append(0x80)
        while len(data) % 128 != 112:
            data.append(0)
        data += orig_len_in_bits.to_bytes(16, byteorder='big')
        for a in range(0, len(data), 128):
            group = data[a : a + 128]
            w = [0 for i in range(80)]
            for i in range(16):
                w[i] = int.from_bytes(group[8*i : 8*i + 8], byteorder='big')
            for j in range(16, 80):
                s0 = (rightrotate_64(w[j-15], 1) ^ rightrotate_64(w[j-15], 8) ^ rightshift(w[j-15], 7)) & 0xFFFFFFFFFFFFFFFF
                s1 = (rightrotate_64(w[j-2], 19) ^ rightrotate_64(w[j-2], 61) ^ rightshift(w[j-2], 6)) & 0xFFFFFFFFFFFFFFFF
                w[j] = (w[j-16] + s0 + w[j-7] + s1) & 0xFFFFFFFFFFFFFFFF
            a, b, c, d, e, f, g, h = h0, h1, h2, h3, h4, h5, h6, h7
            for m in range(80):
                S1 = (rightrotate_64(e, 14) ^ rightrotate_64(e, 18) ^ rightrotate_64(e, 41)) & 0xFFFFFFFFFFFFFFFF
                ch = ((e & f) ^ ((~e) & g)) & 0xFFFFFFFFFFFFFFFF
                temp1 = (h + S1 + ch + self.k[m] + w[m]) & 0xFFFFFFFFFFFFFFFF
                S0 = (rightrotate_64(a, 28) ^ rightrotate_64(a, 34) ^ rightrotate_64(a, 39)) & 0xFFFFFFFFFFFFFFFF
                maj = ((a & b) ^ (a & c) ^ (b & c)) & 0xFFFFFFFFFFFFFFFF
                temp2 = (S0 + maj) & 0xFFFFFFFFFFFFFFFF
                a1 = (temp1 + temp2) & 0xFFFFFFFFFFFFFFFF
                e1 = (d + temp1) & 0xFFFFFFFFFFFFFFFF
                a, b, c, d, e, f, g, h = a1, a, b, c, e1, e, f, g

            h0 = (h0 + a) & 0xFFFFFFFFFFFFFFFF
            h1 = (h1 + b) & 0xFFFFFFFFFFFFFFFF
            h2 = (h2 + c) & 0xFFFFFFFFFFFFFFFF
            h3 = (h3 + d) & 0xFFFFFFFFFFFFFFFF
            h4 = (h4 + e) & 0xFFFFFFFFFFFFFFFF
            h5 = (h5 + f) & 0xFFFFFFFFFFFFFFFF
            h6 = (h6 + g) & 0xFFFFFFFFFFFFFFFF
            h7 = (h7 + h) & 0xFFFFFFFFFFFFFFFF
        self.hash_pieces = [h0, h1, h2, h3, h4, h5, h6, h7]

    def digest(self):
        mod_hashPieces = self.hash_pieces[:-2]
        return sum(leftshift(x, 64*i) for i, x in enumerate(mod_hashPieces[::-1]))
    
    def hexdigest(self):
        digest = self.digest()
        raw = digest.to_bytes(self.digest_size, byteorder='big')
        format_str = '{:0' + str(2 * self.digest_size) + 'x}'
        return format_str.format(int.from_bytes(raw, byteorder='big'))

def main():
    string = input("Input : ")
    h = SHA384()
    data = bytes(string, encoding='utf8')
    h.update(data)
    print(f"The hexadecimal equivalent of SHA384 is:\n {h.hexdigest()}")

main()
