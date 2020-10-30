from random import randint
import base64


def get_prime(min_, max_):
    p = randint(min_, max_) * 6 - 1
    if not is_prime(p): p += 2
    return p

def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0: return False
        i += 1
    return True

def bezout_recursive(a, b):
    x, xx, y, yy = 1, 0, 0, 1
    while b:
        q = a // b
        a, b = b, a % b
        x, xx = xx, x - xx * q
        y, yy = yy, y - yy * q
    return (x, y, a)

def encrypt(msg, key):
    arr = []
    for char in list(str(msg)):
        arr += [ (ord(char)**key[0]) % key[1] ]
    return arr

def decrypt(encrypted_msg, key):
    msg = b""
    for cell in encrypted_msg:
        msg += chr( (cell**key[0]) % key[1] ).encode()
    return msg


p = get_prime(1, 10)
q = get_prime(1, 10)
if q == p:
    q += 6 if is_prime(q + 6) else 8
n = p * q
fi_n = (p - 1) * (q - 1)

e = randint(2, fi_n - 1)

gcd = bezout_recursive(e, fi_n)[-1]
while gcd != 1:
    e /= gcd
    gcd = bezout_recursive(e, fi_n)[-1]
e = int(e)

d = bezout_recursive(e, fi_n)[0]
if d < 0:
    d += fi_n

print("p:\t", p)
print("q:\t", q)
print("Fi(n):\t", fi_n)
print("Public key:\t({}, {})".format(e, n))
print("Privite key:\t({}, {})".format(d, n))

msg = input("Enter text: ")
msg = base64.b64encode(str.encode(msg))
encrypted = encrypt(msg, (e, n))
print("Encrypted message:", encrypted)

decrypted_msg = decrypt(encrypted, (d, n))
decrypted_msg = decrypted_msg.decode("utf-8")[2:-1]
decrypted_msg = decrypted_msg.encode()
decrypted_msg = base64.decodebytes(decrypted_msg).decode("utf-8")
print ("Decrypted message:", decrypted_msg)
