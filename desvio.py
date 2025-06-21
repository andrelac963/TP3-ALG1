def calcular_desvios(casos_teste):
 """
 Calcula o desvio percentual da solução aproximada em relação à solução exata.
 """
 desvios = []
 for caso in casos_teste:
     resultado_exato = caso['resultado_exato']
     resultado_aproximado = caso['resultado_aproximado']
     
     # Calcula o desvio percentual
     desvio = ((resultado_aproximado - resultado_exato) / resultado_exato) * 100
     desvios.append({'instancia': caso['instancia'], 'desvio_percentual': desvio})
 
 # Calcula o desvio médio
 desvio_medio = sum(d['desvio_percentual'] for d in desvios) / len(desvios)
 
 return desvios, desvio_medio

# Casos de teste fornecidos
casos_teste = [
 {'instancia': 'instancia_3p.txt', 'resultado_exato': 8, 'resultado_aproximado': 8},
 {'instancia': 'instancia_7p.txt', 'resultado_exato': 22, 'resultado_aproximado': 23},
 {'instancia': 'instancia_10p.txt', 'resultado_exato': 34, 'resultado_aproximado': 36},
 {'instancia': 'instancia_12p.txt', 'resultado_exato': 42, 'resultado_aproximado': 43},
 {'instancia': 'instancia_15p.txt', 'resultado_exato': 43, 'resultado_aproximado': 50},
 {'instancia': 'instancia_16p.txt', 'resultado_exato': 57, 'resultado_aproximado': 68},
 {'instancia': 'instancia_17p.txt', 'resultado_exato': 53, 'resultado_aproximado': 53},
 {'instancia': 'instancia_18p.txt', 'resultado_exato': 51, 'resultado_aproximado': 58},
]

# Calcula os desvios
desvios, desvio_medio = calcular_desvios(casos_teste)

# Exibe os resultados
print("Desvios por instância:")
for desvio in desvios:
 print(f"Instância: {desvio['instancia']}, Desvio Percentual: {desvio['desvio_percentual']:.2f}%")

print(f"\nDesvio Médio: {desvio_medio:.2f}%")