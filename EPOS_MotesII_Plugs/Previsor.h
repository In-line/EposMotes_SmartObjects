
__USING_SYS

struct {
int previsao;
int endereco;
int prioridade;
Mensagem::Tipo tipo;
} infoTomada;

class Previsor{

public:

static double preverDia(int mediaHoraria[24],int horaAtual){
	double soma = 0;
	for(int i = 0; i < horaAtual+1;i++){
		soma += mediaHoraria[i];
	}
	double media = soma / horaAtual;
	soma += media * (24 - horaAtual);
	return soma;
}

static double preverProprio(int mediaDiariaPorMes[30], int diaAtual){
	double soma = 0;
	for(int i = 0; i < diaAtual; i++){
		soma += mediaDiariaPorMes[i];
	}
	 
	double media = soma/diaAtual;
	
	soma += media * (30 - diaAtual);
	
	return soma;
}

static double preverTotal(infoTomada[] *tomadas, int sizeTomadas, double previsaoPropria){
	double previsaoTotal = 0;
	for(int i = 0; i < sizeTomadas;i++){
		previsaoTotal += tomadas -> previsao;
	}
	previsaoTotal += previsaoPropria;
	return previsaoTotal;
}

}
