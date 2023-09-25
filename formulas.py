def juros(p, n, i):
    return (1 + i)**n * p

def fator_vp(n, i):
    return ((1 + i)**n - 1) / ((1 + i)**n * i)

def fator_vf(n, i):
    return ((1 + i)**n - 1 ) / (i)

def valor_postecipado(p, n, i):
    return p / fator_vp(n, i)

def valor_antecipado(p, n, i):
    return p / (fator_vp(n-1, i) + 1)

def diferida_antecipada(p, n, i, c):
    return juros(p, c-1, i) / fator_vp(n, i)

def diferida_postecipada(p, n, i, c):
    return juros(p, c, i) / fator_vp(n, i)

def montate_uniforme(r, n, i):
    return r * fator_vf(n, i)

def parcela_uniforme(s, n, i):
    return s / fator_vf(n, i)

x = 10000 * fator_vp(13, 0.126162)

print(round(63900-x, 2))

