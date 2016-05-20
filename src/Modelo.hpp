/*
 * Modelo.hpp
 *
 *  Created on: 16/04/2015
 *      Author: mateus
 */

#ifndef MODELO_HPP_
#define MODELO_HPP_

#include "Biblioteca.hpp"

#define TipoLocalizacao vector < vector < float > >

#define TipoTCVP vector < int >
#define TipoCVP vector < vector < int > >
#define TipoTCDE vector < int >
#define TipoCDE vector < vector < int > >

#define TipoDistancia vector < vector < float > >

#define TipoPvi vector < vector < vector < float > > >
#define TipoTPp vector < float >
#define TipoOmega vector <  float  >
#define TipoSvii vector < vector < vector < float  > > >

#define TipoTminE vector <  float  >
#define TipoTmaxE vector <  float  >
#define TipoTminP vector <  float  >
#define TipoTmaxP vector <  float  >

#define TipoAlfa IloArray<IloArray<IloBoolVarArray> >
#define TipoBeta IloArray< IloArray< IloArray< IloArray< IloBoolVarArray > > > >

#define TipoTvei IloArray < IloArray < IloFloatVarArray > >
#define TipoTPvei IloArray < IloArray < IloFloatVarArray > >

#define TipoZe IloFloatVarArray
#define TipoZr IloFloatVarArray


class No{

public:
    No();                                       // construtora da classe

    /*
 // Escreve arquivo TXT

    int NumPlantas;						// Número de plantas
    int NumEntregas;					// Número de entregas
    int NumVeiculos;					// Número de veículos

    float Velocidade;
    float TempoDeVidaConcreto;

    TipoTCVP TamanhoConjuntoVeiculoPlanta;
    TipoCVP ConjuntoVeiculoPlanta;

    TipoTCDE TamanhoConjuntoDemandasEntrada;
    TipoCDE ConjuntoDemandasEntrada;

    TipoLocalizacao Localizacao;
    TipoDistancia DistanciaPlantaEntrega;
    TipoDistancia DistanciaEntregaPlanta;

    TipoPvi TempoParaDescarregamento;
    TipoTPp  TempoNaPlanta;

    TipoOmega TempoEntreChegadas;

    TipoTminE TempoInicioEntrada;
    TipoTmaxE TempoFinalEntrada;

    TipoTminP TempoInicioPlanta;
    TipoTmaxP TempoFinalPlanta;
*/

// Funções

    //void PreencheEstrutura();
    //void CriaTXT();

//	Funções de leitura do arquivo
    void LeNomeInstancia(int, string&);
    void LeNumeroPlantasEntregasVeiculos(int);
    void LeVelocidadeTempoVidaConcreto(int);
    void LeVeiculoPorPlanta(int);
    void LeDemandasPorEntrada(int);
    void LeDistanciaPlantaEntrada(int);
    void LeDistanciaEntregaPlanta(int);
    void LeTempoProcessamentoEntrega(int);
    void LeTempoCarregamentoPlanta(int);
    void LeTempoMaximoEntreEntregasConsecultivas(int);
    void CalculaTempoMinimoDeAtendimentoEntreDuasEntregas(int);
    void LeIntervalosNasEntregas(int);
    void LeIntervalosNasPlantas(int);

    int  LeDados(string, int );

// Le arquivo para resolver o CPLEX, parametros
    ifstream arq;

    int 		NP;			// Número de plantas
	int 		NE;			// Número de entregas
	int 		NV;			// Número de veículos

	float 		V;			// Velocidade dos caminhões
	float 		TVC;		// Tempo de vida do concreto

	TipoTCVP 	TCVP;		// Tamanho do conjunto de veículos (caminhões) por planta
	TipoCVP 	CVP;		// Conjunto de veículos (caminhões) por planta

	TipoTCDE 	TCDE;		// Tamanho do conjunto de demandas por entregas
	TipoCDE 	CDE;		// Conjunto de demanas por entrega

	TipoLocalizacao L;		// coordenada dos pontos
	TipoDistancia Dpe;		// Distancia entre uma planta e um entrega
	TipoDistancia Dep;		// Distancia entre uma entrega e uma planta

	TipoPvi		Pvi;		// Tempo para se descarregar o veiculo para a demanda i
	TipoTPp		TPp;		// Tempo para se carregar na planta

	TipoOmega	Omega;		// Tempo entre carregamentos máximo

	TipoSvii	Svii;		// Tempo minimo para se atender duas demandas

	TipoTminE	TminE;		// Tempo mínimo na construção
	TipoTmaxE	TmaxE;		// Tempo máximo na construção

	TipoTminP	TminP;		// Tempo mínimo na planta
	TipoTmaxP	TmaxP;		// Tempo máximo na planta


// Variaveis do CPLEX
	IloEnv env;

// Funções que inicializam as variaveis do modleo
	void CriaAlfa(TipoAlfa& , int);
	void CriaBeta(TipoBeta&, int);
	void CriaBetaProducao(TipoBeta&, int);
	void CriaTvei( TipoTvei& ,int);
	void CriaTPvei( TipoTPvei&,int);
	void CriaZe(TipoZe&, int);
	void CriaZr(TipoZr&, int);



// Funções Objetivo
	void FuncaoObjetivo(TipoZe, TipoZr,  IloModel&, int);
//Restrições
	void Restricao_AtendimentoDasDemandas(TipoAlfa, IloModel&, int );
	void Restricao_LowerBoundZe(TipoZe, TipoTvei, TipoAlfa , IloModel& );
	void Restricao_VinculoTveiTPvei(TipoAlfa, TipoTPvei, TipoTvei,IloModel&, int);
	void Restricao_LowerBoundZr( TipoZr, TipoTvei, TipoAlfa, IloModel&, int);
	void Restricao_PrecedenciaTvei( TipoAlfa ,TipoBeta, TipoTvei, IloModel&, int , int );
	void Restricao_TempoMaximoEntreDescarregamentosSeguidosNaMesmaEntrega( TipoAlfa ,TipoTvei, IloModel&, int);
	void Restricao_TempoMinimoEntreDescarregamentosSeguidosNaMesmaEntrega(TipoAlfa, TipoTvei, IloModel&, int);
	void Restricao_PrecedenciaTPvei( TipoAlfa,TipoBeta,TipoTPvei, IloModel&, int, int);
	void Restricao_TempoDeVidaDoConcreto( TipoAlfa,TipoTvei, TipoTPvei, IloModel&, int);
	void Restricao_LimiteDeTempoNaEntrega( TipoTvei, IloModel&, int );
	void Restricao_LimiteDeTempoNaPlanta( TipoTvei, IloModel&, int);

	void ForcaSolucaoColocandoRestricoes(string, TipoAlfa, TipoBeta, TipoTvei, TipoBeta, TipoTPvei, IloModel&);

	void VerificaOuCriaPastaOut(int);
	void VerificaOuCriaPastaSol(int);

	void EscreveVariaveisAlfaDoModeloAposResolucao(int , int ,ofstream& , IloCplex , TipoAlfa );
	void EscreveVariaveisBetaDoModeloAposResolucao(int, int, ofstream&, IloCplex,  TipoBeta);
	void EscreveVariaveisBetaProducaoDoModeloAposResolucao(int, int, ofstream&, IloCplex, TipoBeta);
	void EscreveVariaveisTveiDoModeloAposResolucao(int, int, ofstream&, IloCplex, TipoTvei);
	void EscreveVariaveisTPveiDoModeloAposResolucao(int, int, ofstream&, IloCplex, TipoTPvei);
	void EscreveVariaveisZeDoModeloAposResolucao(int, int, ofstream&, IloCplex, TipoZe);
	void EscreveVariaveisZrDoModeloAposResolucao(int , int ,ofstream&, IloCplex, TipoZr);
	void EscreveVariaveisAEeRoAEePEeRoPEeDoModeloAposResolucao(int, int, ofstream&, IloCplex );
	void EscreveVariaveisAPpRoAPpPPpRoPPpDoModeloAposResolucao(int, int, ofstream&, IloCplex);



	void EscreveItinerarioVeiculos(int, int, ofstream&, IloCplex, TipoAlfa, TipoTvei, TipoTPvei);
	void EscreveEntregasNosClientes(int, int, ofstream&, IloCplex, TipoAlfa, TipoTvei);
	void EscreveUtilizacaoVeiculos(int, int, ofstream&, IloCplex, TipoAlfa, TipoTvei);


// Funções que chama o Cplex

	int Cplex(string, int , int&, float&, float&, float&, float&);

// Escrever em diretorio a saída

    char *c1;
    char *c2;
    string Nome1;
    string Nome2;

 // Pegar o tempo

    float Tempo1;
    float Tempo2;

    ~No();       // Destruidora
};

No::No(){

	NP  = 0;
	NE  = 0;
	NV  = 0;
	V = 0;
	TVC = 0;
	c1 = NULL;
	c2 = NULL;
	Tempo1 = -13;
	Tempo2 = -13;
}

/*
void No::PreencheEstrutura(){

// Coloca o numero de plantas, entregas, veiculos e velocidade
	NumPlantas 	= NumeroDePlantasVariaveisFixas;
	NumEntregas = NumeroDeEntregasVariaveisFixas;
	NumVeiculos = NumeroDeVeiculosVariaveisFixas;
	Velocidade 	= VelocidadeVariaveisFixas;
	TempoDeVidaConcreto = TempoDeVidaConcretoVariaveisFixas;

// Preenche o numero veiculos por planta
	TamanhoConjuntoVeiculoPlanta.resize( NumPlantas );
	TamanhoConjuntoVeiculoPlanta[0]	=	3;
	TamanhoConjuntoVeiculoPlanta[1]	=	2;

	ConjuntoVeiculoPlanta.resize( NumPlantas );
	ConjuntoVeiculoPlanta[0].resize( TamanhoConjuntoVeiculoPlanta[0] );
	ConjuntoVeiculoPlanta[1].resize( TamanhoConjuntoVeiculoPlanta[1] );

	int aux1;
	int aux2;
	aux1 = 0;
	aux2 = 0;
	for (int i = 0; i < NumVeiculos ; i ++){
		if( aux1 == TamanhoConjuntoVeiculoPlanta[aux2]){
			aux2 = aux2 + 1 ;
			aux1 = 0;
		}
		ConjuntoVeiculoPlanta[aux2][aux1] = i+1;
		aux1 = aux1 + 1;
	}

// Preenche o numero de demandas por entrada
	TamanhoConjuntoDemandasEntrada.resize(NumEntregas);
	TamanhoConjuntoDemandasEntrada[0] = 2;
	TamanhoConjuntoDemandasEntrada[1] = 1;
	TamanhoConjuntoDemandasEntrada[2] = 3;
	TamanhoConjuntoDemandasEntrada[3] = 2;

	ConjuntoDemandasEntrada.resize(NumEntregas);
	for( int i = 0; i < NumEntregas ; i++){
		ConjuntoDemandasEntrada[i].resize( TamanhoConjuntoDemandasEntrada[i] );
		for( int j = 0; j < TamanhoConjuntoDemandasEntrada[i] ; j++){
			ConjuntoDemandasEntrada[i][j] = j + 1;
		}
	}

// Preenche as localizações das plantas e entradas
	Localizacao.resize( NumPlantas + NumEntregas);
	for( int i = 0 ; i < NumPlantas + NumEntregas ; i++){
		Localizacao[i].resize( 2);
	}

	// Localização plantas (x,Y)
	Localizacao[0][0]= -7;	Localizacao[0][1]= 1; // planta 1
	Localizacao[1][0]= -2;	Localizacao[1][1]= 1; // planta 2

	// Localização entradas (x,Y)
	Localizacao[2][0]= -9;	Localizacao[2][1]= 9; //Entrada 1
	Localizacao[3][0]= -9;	Localizacao[3][1]= -5;//Entrada 2
	Localizacao[4][0]= -4;	Localizacao[4][1]= 6; //Entrada 3
	Localizacao[5][0]= 0;	Localizacao[5][1]= -5;//Entrada 4

// Distâncias das Plantas para as Entradas /
	DistanciaPlantaEntrega.resize( NumPlantas);
	for( int i = 0; i <  NumPlantas; i++){
		DistanciaPlantaEntrega[i].resize( NumEntregas);
	}
	for( int i = 0; i <  NumPlantas; i++){
	    for( int j = NumPlantas; j <  (NumPlantas + NumEntregas); j++){
	    	DistanciaPlantaEntrega[i][j-NumPlantas] = sqrt( pow( Localizacao[i][0] - Localizacao[j][0],2) + pow( Localizacao[i][1] - Localizacao[j][1],2) ) / Velocidade;
	   	}
	}

// Distâncias das Entradas para as Plantas
	DistanciaEntregaPlanta.resize( NumEntregas);
		for( int i = 0; i <  NumEntregas; i++){
			DistanciaEntregaPlanta[i].resize( NumPlantas);
		}

	for( int i = NumPlantas; i <  (NumPlantas + NumEntregas); i++){
		for( int j = 0; j <  NumPlantas; j++){
			DistanciaEntregaPlanta[i-NumPlantas][j] = sqrt( pow( Localizacao[i][0] - Localizacao[j][0],2) + pow( Localizacao[i][1] - Localizacao[j][1],2) ) / Velocidade;
		}
	}

// Tempo para descarregamento de cada veiculo
	TempoParaDescarregamento.resize( NumVeiculos);
	for( int i = 0; i <  NumVeiculos; i++){
		TempoParaDescarregamento[i].resize( NumEntregas);
		for( int j = 0; j <  NumEntregas; j++){
			TempoParaDescarregamento[i][j].resize(TamanhoConjuntoDemandasEntrada[j]);
			for( int z = 0; z <  TamanhoConjuntoDemandasEntrada[j]; z++){
			TempoParaDescarregamento[i][j][z] = 0.2;
			}
		}
	}

// Tempo na planta para carregamento
	TempoNaPlanta.resize( NumPlantas);
	for( int p = 0; p < NumPlantas; p++){
		TempoNaPlanta[p] = 0.083333333; // equivalente a 5 minutos(4 min = 0.066667 ; 3min = 0.05 e 2min = 0.0333333)
	}

// Tempo entre chegadas
	TempoEntreChegadas.resize(NumEntregas);
	for( int j = 0; j <  NumEntregas; j++){
		TempoEntreChegadas[j] = 0.3;
	}

//  Tempo inicio e termino Entrada
	 TempoInicioEntrada.resize(NumEntregas);
	 for( int i = 0; i <  NumEntregas; i++){
		 TempoInicioEntrada[i] = 8;
	 }
	 TempoFinalEntrada.resize(NumEntregas);
	 for( int i = 0; i <  NumEntregas; i++){
		TempoFinalEntrada[i] = 16;
	 }

 //  Tempo inicio e termino Planta
	 TempoInicioPlanta.resize(NumPlantas);
	 for( int i = 0; i <  NumPlantas; i++){
		 TempoInicioPlanta[i] = 8;
	 }
	 TempoFinalPlanta.resize(NumPlantas);
	 for( int i = 0; i <  NumPlantas; i++){
		TempoFinalPlanta[i] = 16;
	 }

}


void No::CriaTXT(){

	ofstream Instancia;
	Instancia.open("./InstS/T-M-V1.txt");

cout << "T-M-V1" << endl;
	Instancia <<"T-M-V1" << endl;

cout << " Numero de Plantas " << endl << '\t';
    cout << NumPlantas << endl;
    Instancia << NumPlantas << endl;

cout << " Numero de Entregas " << endl << '\t';
    cout << NumEntregas << endl;
    Instancia << NumEntregas << endl;

cout << " Numero de Veículos " << endl << '\t';
    cout << NumVeiculos <<  endl;
    Instancia << NumVeiculos  << endl;

cout << " Velocidade " << endl << '\t';
	cout << Velocidade <<  endl;
    Instancia << Velocidade  << endl;

cout << " Tempo de Vida do Concreto " << endl << '\t';
	cout << TempoDeVidaConcreto <<  endl;
	Instancia << TempoDeVidaConcreto  << endl;

cout << "Conjunto de Veiculos por Planta " << endl;
    for( int i = 0; i <  NumPlantas; i++){
    	cout << '\t' << "Planta " << i + 1 <<  " ( " << TamanhoConjuntoVeiculoPlanta[i] << " ) -> ";
    	Instancia << TamanhoConjuntoVeiculoPlanta[i] << " ";
    	for( int j = 0; j <  TamanhoConjuntoVeiculoPlanta[i]; j++){
    		cout << ConjuntoVeiculoPlanta[i][j] << " ";
    		Instancia << ConjuntoVeiculoPlanta[i][j] << " ";
    	}
    	cout << endl;
    	Instancia << endl;
	}

cout << "Conjunto de Demandas por Entrega " << endl;
	for( int i = 0; i <  NumEntregas; i++){
		cout << '\t' << "Entrega " << i + 1 <<  " ( " << TamanhoConjuntoDemandasEntrada[i] << " ) -> ";
		Instancia << TamanhoConjuntoDemandasEntrada[i] << " ";
		for( int j = 0; j <  TamanhoConjuntoDemandasEntrada[i]; j++){
			cout << ConjuntoDemandasEntrada[i][j] << " ";
			Instancia << ConjuntoDemandasEntrada[i][j] << " ";
		}
		cout << endl;
		Instancia << endl;
	}

cout << "Distancia Planta - Entrega " << endl;
	cout << ' ';
	for( int j = 0; j <  NumEntregas; j++){
		cout << '\t' << j+1 ;
	}
	cout << endl;
	for( int i = 0; i <  NumPlantas; i++){
		cout << i+1 << '\t';
		for( int j = 0; j <  NumEntregas; j++){
			cout << DistanciaPlantaEntrega[i][j] << '\t';
			Instancia << DistanciaPlantaEntrega[i][j] << " ";
		}
		cout << endl;
		Instancia << endl;
	}

cout << "Distancia Entrega - Planta " << endl;
	cout << ' ';
	for( int j = 0; j <  NumPlantas; j++){
		cout << '\t' << j+1 ;
	}
	cout << endl;
	for( int i = 0; i <  NumEntregas; i++){
		cout << i+1 << '\t';
		for( int j = 0; j <  NumPlantas; j++){
			cout << DistanciaEntregaPlanta[i][j] << '\t';
			Instancia << DistanciaEntregaPlanta[i][j] << " ";
		}
		cout << endl;
		Instancia << endl;
	}

cout << "Tempo Para Descarregamento " << endl;
	for( int i = 0; i <  NumVeiculos; i++){
	cout << '\t' << '\t' << "Veiculo " << i+1 << endl;
	Instancia << i+1 << endl;
		for( int j = 0; j <  NumEntregas; j++){
			cout << "Entrega " << j+1 << " (" << TamanhoConjuntoDemandasEntrada[j] << ") " <<  '\t';
			Instancia << TamanhoConjuntoDemandasEntrada[j] << '\t';
			for( int z = 0; z <  TamanhoConjuntoDemandasEntrada[j]; z++){
			cout << TempoParaDescarregamento[i][j][z] << '\t';
			Instancia << TempoParaDescarregamento[i][j][z] << '\t';
			}
			cout << endl;
			Instancia << endl;
		}
	}

cout << "Tempo Para Carregamento " << endl;
	for( int p = 0; p < NumPlantas; p++){
		Instancia <<  TempoNaPlanta[p] << '\t';
		cout  << TempoNaPlanta[p] << '\t';
	}
	cout << endl;
	Instancia << endl;

cout << " Tempo entre chagadas " << endl;
	for( int j = 0; j <  NumEntregas; j++){
		cout << TempoEntreChegadas[j] << '\t';
		Instancia << TempoEntreChegadas[j] << '\t';
	}
	cout << endl;
	Instancia << endl;

cout << " Tempo Inicio Entrada " << endl;
	 for( int i = 0; i <  NumEntregas; i++){
		cout << i << ' ' << TempoInicioEntrada[i]<< endl;
		Instancia << TempoInicioEntrada[i] << ' ';
	 }
	 cout << endl;
	 Instancia << endl;

cout << " Tempo Final Entrada " << endl;
	 for( int i = 0; i <  NumEntregas; i++){
		cout << i << ' ' << TempoFinalEntrada[i]<< endl;
		Instancia << TempoFinalEntrada[i] << ' ';
	 }
	 cout << endl;
	 Instancia << endl;

cout << " Tempo Inicio Planta " << endl;
	 for( int i = 0; i <  NumPlantas; i++){
		 cout << i << ' ' << TempoInicioPlanta[i] << endl;
		 Instancia << TempoInicioPlanta[i] << ' ';
	 }
	 cout << endl;
	 Instancia << endl;

cout << " Tempo Final Planta " << endl;
	 for( int i = 0; i <  NumPlantas; i++){
		 cout << i << ' ' << TempoFinalPlanta[i] << endl;
		 Instancia << TempoFinalPlanta[i] << ' ';
	 }
	 cout << endl;
	 Instancia << endl;

	 Instancia.close();
}

*/

// Le dadso da Intância
void No::LeNomeInstancia(int comentarios, string& Instancia){
	arq >> Instancia;
	if( comentarios == 1){
		cout << " Nome instancia "<<  Instancia << endl;
	}
}
void No::LeNumeroPlantasEntregasVeiculos(int comentarios){
	arq >> NP;
	arq >> NE;
	arq >> NV;
	if( comentarios == 1){
		cout << " Numero de plantas "<<  NP << endl;
		cout << " Numero de Entregas "<< NE << endl;
		cout << " Numero de Veiculos "<< NV << endl;
	}
}
void No::LeVelocidadeTempoVidaConcreto(int comentarios){
	arq >> V;
	arq >> TVC;
	if( comentarios == 1){
		cout << " V (velocidade)  "<< V << endl;
		cout << " TVC (tempo de vida do concreto) "<< TVC << endl;
	}
}
void No::LeVeiculoPorPlanta(int comentarios){
	if( comentarios == 1){
		cout << "Conjunto de Veiculos por Planta " << endl;
	}
	TCVP.resize(NP);
	CVP.resize(NP);
	for( int i = 0; i < NP ; i++){
		arq >> TCVP[i];
		if( comentarios == 1){
			cout << '\t' << "Planta " << i + 1 <<  " ( " << TCVP[i] << " ) -> ";
		}
		CVP[i].resize(TCVP[i]);
		for( int j = 0; j < TCVP[i] ; j++){
			arq >>  CVP[i][j];
			if( comentarios == 1){
				cout << CVP[i][j] << " ";
			}
		}
		if( comentarios == 1){
			cout << endl;
		}
	}
	if( comentarios == 1){
		cout << endl;
	}
}
void No::LeDemandasPorEntrada(int comentarios){
	if( comentarios == 1){
		cout << "Conjunto de Demandas por Entrega " << endl;
	}
	TCDE.resize(NE);
	CDE.resize(NE);
	for( int i = 0; i < NE ; i++){
		arq >> TCDE[i];
		if( comentarios == 1){
			cout << '\t' << "Entrega " << i + 1 <<  " ( " << TCDE[i] << " ) -> ";
		}
		CDE[i].resize(TCDE[i]);
		for( int j = 0; j < TCDE[i] ; j++){
			arq >>  CDE[i][j];
			if( comentarios == 1){
				cout << CDE[i][j] << " ";
			}
		}
		if( comentarios == 1){
			cout << endl;
		}
	}
	if( comentarios == 1){
		cout << endl;
	}
}
void No::LeDistanciaPlantaEntrada(int comentarios){
	Dpe.resize(NP);
	for(int p = 0; p < NP; p++){
		Dpe[p].resize(NE);
	}

	if( comentarios == 1){
		cout << "Distancia Planta - Entrega " << endl;
		cout << ' ';
		for( int e = 0; e <  NE; e++){
			cout << '\t' << e+1 ;
		}
		cout << endl;
	}
	for( int p = 0; p <  NP; p++){
		if( comentarios == 1){
			cout << p+1 << '\t';
		}
		for( int e = 0; e <  NE; e++){
			arq >> Dpe[p][e];
			if( comentarios == 1){
				cout << Dpe[p][e] << " ";
			}
		}
		if( comentarios == 1){
			cout << endl;
		}
	}
}
void No::LeDistanciaEntregaPlanta(int comentarios){
	Dep.resize(NE);
	for(int e = 0; e < NE; e++){
		Dep[e].resize(NP);
	}

	if( comentarios == 1){
		cout << "Distancia Entrega - Planta " << endl;
		cout << ' ';
		for( int p = 0; p <  NP; p++){
			cout << '\t' << p+1 ;
		}
		cout << endl;
	}
	for( int e = 0; e <  NE; e++){
		if( comentarios == 1){
			cout << e+1 << '\t';
		}
		for( int p = 0; p <  NP; p++){
			arq >> Dep[e][p];
			if( comentarios == 1){
				cout << Dep[e][p] << " ";
			}
		}
		if( comentarios == 1){
			cout << endl;
		}
	}
}
void No::LeTempoProcessamentoEntrega(int comentarios){
	int Aux1;

	Pvi.resize( NV);
	for( int i = 0; i <  NV; i++){
		Pvi[i].resize( NE);
		for( int j = 0; j <  NE; j++){
			Pvi[i][j].resize(TCDE[j]);
		}
	}

	if( comentarios == 1){
		cout << "Tempo Para Descarregamento " << endl;
	}

	for( int i = 0; i <  NV; i++){
		arq >> Aux1;
		if( comentarios == 1){
			cout << '\t' << '\t' << "Veiculo " << Aux1 << endl;
		}
		for( int j = 0; j <  NE; j++){
			arq >> Aux1;
			if( comentarios == 1){
				cout << "Entrega " << j+1 << " (" << Aux1 << ") " <<  '\t';
			}
			for( int z = 0; z <  Aux1; z++){
				arq >> Pvi[i][j][z];
				if( comentarios == 1){
					cout << Pvi[i][j][z] << '\t';
				}
			}
			if( comentarios == 1){
				cout << endl;
			}
		}
	}
}
void No::LeTempoCarregamentoPlanta(int comentarios){
	TPp.resize(NP );
	if( comentarios == 1){
		cout << "Tempo Para Carregamento nas Plantas " << endl;
	}
	for( int p = 0; p < NP; p++){
		arq >> TPp[p];
		if( comentarios == 1){
			cout << TPp[p] << '\t';
		}
	}
	if( comentarios == 1){
		cout << endl;
	}
}
void No::LeTempoMaximoEntreEntregasConsecultivas(int comentarios){
	Omega.resize(NE);
	if( comentarios == 1){
		cout << " Tempo entre chagadas " << endl;
	}
	for( int e = 0; e <  NE; e++){
		arq >>Omega[e];
		if( comentarios == 1){
			cout <<Omega[e] << '\t';
		}
	}
	if( comentarios == 1){
		cout << endl;
	}
}

void No::CalculaTempoMinimoDeAtendimentoEntreDuasEntregas(int comentarios){
	int Aux2;

	Svii.resize(NV);
	for( int v = 0; v <  NV; v++){
		 Svii[v].resize(NE);
		 for( int e1 = 0; e1 <  NE; e1++){
			 Svii[v][e1].resize(NE);;
		 }
	}
	if( comentarios == 1){
		cout << " Tempo para ir de uma entrada a outra " << endl;
	}
	Aux2 = 0;
	for( int p = 0; p <  NP; p++){
		for( int v = 0; v < TCVP[p]; v++ ){
			if( comentarios == 1){
				cout << '\t' << '\t' << "Veiculo " << Aux2 + 1 << endl ;
			}
			for( int e1 = 0; e1 <  NE; e1++){
				for( int e2 = 0; e2 <  NE; e2++){
					if( comentarios == 1){
						cout << " Entrega [" << e1 + 1 << "] para a Entrega [" << e2+ 1 << "] = ";
					}
					for( int j = 0; j < TCDE[e2]; j++){
						Svii[Aux2][e1][e2] = Dep[e1][p] + TPp[p] + Dpe[p][e2];
						if( comentarios == 1){
							cout << Svii[Aux2][e1][e2] << '\t';
						}
					}
					if( comentarios == 1){
						cout << endl;
					}
				}
				if( comentarios == 1){
					cout << endl;
				}
			 }
			Aux2 = Aux2 + 1;
		}
	}
}

// le  tempo inicio e final entrada e planta
void No::LeIntervalosNasEntregas(int comentarios){
	TminE.resize(NE);
	if( comentarios == 1){
		cout << " Tempo Inicio Entrada " << endl;
	}
	 for( int i = 0; i <  NE; i++){
		 arq >> TminE[i];
		 if( comentarios == 1){
			 cout << i + 1 << ' ' << TminE[i]<< endl;
		 }
	 }
	 if( comentarios == 1){
		 cout << endl;
	 }
	TmaxE.resize(NE);
	if( comentarios == 1){
		cout << " Tempo Final Entrada " << endl;
	}
	for( int i = 0; i <  NE; i++){
		arq >> TmaxE[i];
		if( comentarios == 1){
			cout << i + 1 << ' ' << TmaxE[i]<< endl;
		}
	 }
	if( comentarios == 1){
		cout << endl;
	}
}
void No::LeIntervalosNasPlantas(int comentarios){
	 TminP.resize(NP);
	 if( comentarios == 1){
		 cout << " Tempo Inicio Planta " << endl;
	 }
	 for( int i = 0; i <  NP; i++){
		 arq >> TminP[i];
		 if( comentarios == 1){
			 cout << i + 1 << ' ' << TminP[i] << endl;
		 }
	 }
	 if( comentarios == 1){
		 cout << endl;
	 }
	TmaxP.resize(NP);
	if( comentarios == 1){
		cout << " Tempo Final Planta " << endl;
	}
	for( int i = 0; i <  NP; i++){
		arq >> TmaxP[i];
		if( comentarios == 1){
			cout << i + 1 << ' ' << TmaxP[i] << endl;
		}
	}
	if( comentarios == 1){
		cout << endl;
	}
}

// Le dados
int No::LeDados(string Nome, int comentarios){

	string Instancia;
	string CaminhoArquivo1;

// Abre arquivo das instâncias

	CaminhoArquivo1 = "./InstS/";
	CaminhoArquivo1 += Nome;



	arq.open(CaminhoArquivo1.c_str());
	if (arq.is_open()){
		LeNomeInstancia(comentarios, Instancia);
		LeNumeroPlantasEntregasVeiculos(comentarios);
		LeVelocidadeTempoVidaConcreto(comentarios);
		LeVeiculoPorPlanta(comentarios);
		LeDemandasPorEntrada(comentarios);
		LeDistanciaPlantaEntrada(comentarios);
		LeDistanciaEntregaPlanta(comentarios);
		LeTempoProcessamentoEntrega(comentarios);
		LeTempoCarregamentoPlanta(comentarios);
		LeTempoMaximoEntreEntregasConsecultivas(comentarios);
		CalculaTempoMinimoDeAtendimentoEntreDuasEntregas(comentarios);
		LeIntervalosNasEntregas(comentarios);
		LeIntervalosNasPlantas(comentarios);
		arq.close();
		Instancia.clear();
		CaminhoArquivo1.clear();
		return 1;
	}else{
		cout << "         Fudeu Muito! Não abriu o arquivo " << Nome << endl << endl;
		CaminhoArquivo1.clear();
		return 0;
	}
}

// Cria Variáveis
void No::CriaAlfa(TipoAlfa& Alfa, int Escreve){
	char varName[24];
	for (int v = 0; v < NV; v++) {
		Alfa[v] = IloArray< IloBoolVarArray>(env, NE);
		for (int e = 0; e < NE; e++) {
			Alfa[v][e] =  IloBoolVarArray(env, TCDE[e]);
			for (int k = 0; k < TCDE[e]; k++) {
				sprintf(varName, "Alfa_%d_%d_%d", v, e,k);
				Alfa[v][e][k] = IloBoolVar(env,varName);
				if ( Escreve == 1){
					cout << " Alfa["<< v << "][" << e << "][" << k << "] "<< endl;
				}
			}
			if ( Escreve == 1){
				cout << endl;
			}
		}
	}
}
void No::CriaBeta(TipoBeta& Beta, int Escreve ){
	char varName[24];
	for (int v = 0; v < NV; v++) {
		Beta[v] = IloArray< IloArray< IloArray< IloBoolVarArray> > >(env, NE);
		for (int e1 = 0; e1 < NE; e1++) {
			Beta[v][e1] =  IloArray< IloArray< IloBoolVarArray > > (env, TCDE[e1]);
			for (int i = 0; i < TCDE[e1]; i++) {
				Beta[v][e1][i] =   IloArray< IloBoolVarArray >  (env, NE);
				for (int e2 = 0; e2 < NE; e2++) {
					Beta[v][e1][i][e2] =  IloBoolVarArray (env, TCDE[e2]);
					for (int j = 0; j < TCDE[e2]; j++) {
						if( e1 == e2 and i == j){

						}else{
							sprintf(varName, "Beta_%d_%d_%d_%d_%d", v, e1, i, e2,  j);
							Beta[v][e1][i][e2][j] = IloBoolVar(env,varName);
							if ( Escreve == 1){
								cout << " Beta["<< v << "][" << e1 << "][" << i << "][" << e2 << "][" << j << "] "<< endl;
							}
						}
					}
					if ( Escreve == 1){
						cout << endl;
					}
				}
			}
		}
		if ( Escreve == 1){
			cout << endl;
			cout << endl;
		}
	}
}
void No::CriaBetaProducao(TipoBeta& BetaProducao, int Escreve ){
	char varName[24];
	for (int p = 0; p < NP; p++) {
		BetaProducao[p] = IloArray< IloArray< IloArray< IloBoolVarArray> > >(env, NE);
		for (int e1 = 0; e1 < NE; e1++) {
			BetaProducao[p][e1] =  IloArray< IloArray< IloBoolVarArray > > (env, TCDE[e1]);
			for (int i = 0; i < TCDE[e1]; i++) {
				BetaProducao[p][e1][i] =   IloArray< IloBoolVarArray >  (env, NE);
				for (int e2 = 0; e2 < NE; e2++) {
					BetaProducao[p][e1][i][e2] =  IloBoolVarArray (env, TCDE[e2]);
					for (int j = 0; j < TCDE[e2]; j++) {
						if( e1 == e2 and i == j){

						}else{
							sprintf(varName, "BetaProd_%d_%d_%d_%d_%d", p, e1, i, e2,  j);
							BetaProducao[p][e1][i][e2][j] = IloBoolVar(env,varName);
							if ( Escreve == 1){
								cout << " BetaProducao["<< p << "][" << e1 << "][" << i << "][" << e2 << "][" << j << "] "<< endl;
							}
						}
					}
					if ( Escreve == 1){
						cout << endl;
					}
				}
			}
		}
		if ( Escreve == 1){
			cout << endl;
			cout << endl;
		}
	}
}
void No::CriaTvei( TipoTvei& Tvei,int Escreve){
	char varName[24];
	for (int v = 0; v < NV; v++) {
		Tvei[v] = IloArray < IloFloatVarArray >(env,NE);
		for (int e = 0; e < NE; e++) {
			Tvei[v][e] = IloFloatVarArray(env,TCDE[e]);
			for (int i = 0; i < TCDE[e]; i++) {
				sprintf(varName, "Tvei_%d_%d_%d", v, e, i);
				Tvei[v][e][i] = IloFloatVar(env,varName);
				if ( Escreve == 1){
					cout << " Tvei["<< v << "]["<< e << "]["<< i << "] "<< endl;
				}
			}
			if ( Escreve == 1){
				cout << endl;
			}
		}
	}
	if ( Escreve == 1){
		cout << endl;
	}
}
void No::CriaTPvei( TipoTPvei& TPvei,int Escreve){
	char varName[24];
	for (int v = 0; v < NV; v++) {
		TPvei[v] = IloArray < IloFloatVarArray > (env,NV);
		for (int e = 0; e < NE; e++) {
			TPvei[v][e] = IloFloatVarArray(env,TCDE[e]);
			for (int i = 0; i < TCDE[e]; i++) {
				sprintf(varName, "TPvei_%d_%d_%d", v, e, i);
				TPvei[v][e][i] = IloFloatVar(env,varName);
				if ( Escreve == 1){
					cout << " TPvei["<< v << "]["<< e << "]["<< i << "] "<< endl;
					cout << endl;
				}
			}
		}
	}
	if ( Escreve == 1){
		cout << endl;
	}
}
void No::CriaZe(TipoZe& Ze , int Escreve){
	char varName[24];
	for (int e = 0; e < NE; e++) {
		sprintf(varName, "Ze_%d", e);
		Ze[e] = IloFloatVar(env,varName);
		if ( Escreve == 1){
			cout << " Z_Entrada["<< e << "] "<< endl;
		}
	}
	if ( Escreve == 1){
		cout << endl;
	}
}
void No::CriaZr(TipoZr& Zr , int Escreve ){
	char varName[24];
	for (int p = 0; p < NP; p++) {
		sprintf(varName, "Zr_%d", p);
		Zr[p] = IloFloatVar(env,varName);
		if ( Escreve == 1){
			cout << " Z_Retorno["<< p << "] "<< endl;
		}
	}
	if ( Escreve == 1){
		cout << endl;
	}
}



// Função Objetivo
void No::FuncaoObjetivo(TipoZe Ze, TipoZr Zr,  IloModel& model, int Imprime){
	int Ativo;
	Ativo = 0;
	if ( Imprime == 1){
		cout << " MIN  ";
	}
	IloExpr funcao_objetivo(env);
	for (int e = 0; e < NE; e++) {
		funcao_objetivo += Ze[e];
		if ( Imprime == 1){
			if( Ativo == 1){
				cout << "+";
			}
			cout << " Ze[" << e << "] ";
			Ativo = 1;
		}
	}
	for (int p = 0; p < NP; p++) {
		funcao_objetivo += Zr[p];
		if ( Imprime == 1){
			if( Ativo == 1){
				cout << "+";
			}
			cout << " Zr[" << p << "]";
			Ativo = 1;
		}
	}
	if ( Imprime == 1){
		cout << endl;
	}
	IloObjective obj = IloMinimize(env, funcao_objetivo);
	model.add(obj);
	funcao_objetivo.end();
}

// Restrições
	// restrição 1
void No::Restricao_AtendimentoDasDemandas(TipoAlfa Alfa, IloModel& model, int Escreve){
	for (int e = 0; e < NE; e++) {
		for (int i = 0; i < TCDE[e]; i++) {
			IloExpr expr(env);
			for (int v = 0; v < NV; v++) {
				expr += Alfa[v][e][i];
				if ( Escreve == 1){
					if( v < ( NV - 1 ) ) {
						cout << " ALFAvei[" << v << "][" << e << "][" << i << "] +";
					}else{
						cout << " ALFAvei[" << v << "][" << e << "][" << i << "] = 1" << endl;
					}
				}
			}
			model.add(expr == 1);
			expr.end();
		}
	}
}
	// restrição 2
void No::Restricao_LowerBoundZe(TipoZe Ze, TipoTvei Tvei, TipoAlfa Alfa, IloModel& model){
	float BigMauternativo;
	for (int e = 0; e < NE; e++) {
		for (int i = 0; i < TCDE[e]; i++) {
			for (int v = 0; v < NV; v++) {
                BigMauternativo = TmaxE[e] + Pvi[v][e][i];		// M1
				model.add( Ze[e] >=  Tvei[v][e][i] + Pvi[v][e][i] - BigMauternativo  * ( 1 - Alfa[v][e][i]) );
			}
		}
	}
}
	// restrição 3
void No::Restricao_VinculoTveiTPvei(TipoAlfa Alfa, TipoTPvei TPvei, TipoTvei Tvei,IloModel& model, int EscreveRestricao ){
	int vAux;
	float BigMauternativo;
	for (int e = 0; e < NE; e++) {
		for (int i = 0; i < TCDE[e]; i++) {
			vAux = 0;
			for (int p = 0; p < NP; p++) {
				for (int v = 0; v < TCVP[p]; v++) {
					if ( EscreveRestricao == 1){
						cout << " - BigM * ( 1 - ALFAvei[" << vAux << "][" << e << "][" << i << "] )";
						cout << " + TPvi[" << vAux << "][" << e << "][" << i << "] + TPp[" << p << "]";
						cout << "+ Dpe[" << p << "][" << e << "] <= ";
						cout << " Tvi[" << vAux << "][" << e << "][" << i << "] " << endl;				// M2
					}
					BigMauternativo = TmaxP[p] + TPp[p] + Dpe[p][e];
					model.add( - BigMauternativo  * ( 1 - Alfa[vAux][e][i] ) + TPvei[vAux][e][i] + TPp[p] + Dpe[p][e] <= Tvei[vAux][e][i] );
					if ( EscreveRestricao == 1){
						cout << " BigM * ( 1 - ALFAvei[" << vAux << "][" << e << "][" << i << "] )";
						cout << " + TPvi[" << vAux << "][" << e << "][" << i << "] + TPp[" << p << "]";
						cout << "+ Dpe[" << p << "][" << e << "] >= ";
						cout << " Tvi[" << vAux << "][" << e << "][" << i << "] " << endl;
					}
					BigMauternativo = TmaxE[e];				// M3
					model.add( BigMauternativo  * ( 1 - Alfa[vAux][e][i] ) + TPvei[vAux][e][i] + TPp[p] + Dpe[p][e] >= Tvei[vAux][e][i] );
					vAux = vAux + 1;
				}
			}
		}
	}
}
	// restrição 4
void No::Restricao_LowerBoundZr( TipoZr Zr,TipoTvei Tvei, TipoAlfa Alfa, IloModel& model, int EscreveRestricao){
	int vAux;
	float BigMauternativo;
	for (int e = 0; e < NE; e++) {
		for (int i = 0; i < TCDE[e]; i++) {
			vAux = 0;
			for (int p = 0; p < NP; p++) {
				for (int v = 0; v < TCVP[p]; v++) {
					if ( EscreveRestricao == 1){
						cout << " Zr[ " << p << "] >=  Tvei[" << vAux << "][" << e << "][" << i << "] +";
						cout << " Dep[" << vAux << "][" << e << "][" << i << "] + Dep[" << e << "][" << p << "]";
						cout << " - BigM * ( 1 - Alfa[" << vAux << "][" << e << "][" << i << "])" << endl;
					}
					BigMauternativo = TmaxE[e] + Pvi[vAux][e][i] + Dep[e][p];		// M4
					model.add( Zr[p] >=  Tvei[vAux][e][i] + Pvi[vAux][e][i] + Dep[e][p] - BigMauternativo * ( 1 - Alfa[vAux][e][i]) );
					vAux = vAux + 1;
				}
			}
		}
	}

	for (int p = 0; p < NP; p++) {
		if ( EscreveRestricao == 1){
			cout << " Zr[ " << p << "] >=  TminP[" << p <<"]  " << endl;
		}
		model.add( Zr[p] >=  TminP[p] );
	}

}
	// restrição 5 e 6
void No::Restricao_PrecedenciaTvei( TipoAlfa Alfa,TipoBeta Beta,TipoTvei Tvei, IloModel& model, int EscrveRestricao1, int EscreveRestricao2){
	float BigMauternativo;
	for (int v = 0; v < NV; v++) {
		for (int e1 = 0; e1 < NE; e1++) {
			for (int i = 0; i < TCDE[e1]; i++) {
				for (int e2 = 0; e2 < NE; e2++) {
					for (int j = 0; j < TCDE[e2]; j++) {
						if ( i == j and e1 == e2){

						}else{
							if ( EscrveRestricao1 == 1){
								cout << " BigM * ( 1 - ALFAvei[" << v << "][" << e1 << "][" << i << "]) +";
								cout << " BigM * ( 1 - ALFAve'i'[" << v << "][" << e2 << "][" << j << "]) +";
								cout << " BigM * ( 1 - BETAveie'i'[" << v << "][" << e1 << "][" << i << "][" << e2 << "][" << j << "])";
								cout << " + Tve'i'[" << v << "][" << e2 << "][" << j << "] >= Tvei[" << v << "][" << e1 << "][" << i << "]";
								cout << " + Pvei[" << v << "][" << e1 << "][" << i << "]";
								cout << " + Svee'[" << v << "][" << e1 << "][" << e2 << "]" << endl;
							}
							BigMauternativo = TmaxE[e1] + Pvi[v][e1][i] + Svii[v][e1][e2];			// M5
							model.add( BigMauternativo * ( 1 - Alfa[v][e1][i] ) + BigMauternativo * ( 1 - Alfa[v][e2][j] ) + BigMauternativo * ( 1 - Beta[v][e1][i][e2][j] ) + Tvei[v][e2][j] >= Tvei[v][e1][i] + Pvi[v][e1][i] + Svii[v][e1][e2] );
							if ( EscreveRestricao2 == 1){
								cout << " BigM * ( 1 - ALFAvei[" << v << "][" << e1 << "][" << i << "]) +";
								cout << " BigM * ( 1 - ALFAve'i'[" << v << "][" << e2 << "][" << j << "]) +";
								cout << " BigM * BETAveie'i'[" << v << "][" << e1 << "][" << i << "][" << e2 << "][" << j << "]";
								cout << " + Tvei[" << v << "][" << e1 << "][" << i << "] >= Tvei'[" << v << "][" << e2 << "][" << j << "]";
								cout << " + Pvi'[" << v << "][" << e2 << "][" << j << "]";
								cout << " + Svi'i[" << v << "][" << e2 << "][" << e1 << "]" << endl << endl;
							}
							BigMauternativo = TmaxE[e2] + Pvi[v][e2][j] + Svii[v][e2][e1];		// M6
							model.add( BigMauternativo * ( 1 - Alfa[v][e1][i] ) + BigMauternativo * ( 1 - Alfa[v][e2][j] ) + BigMauternativo * Beta[v][e1][i][e2][j] + Tvei[v][e1][i] >= Tvei[v][e2][j] + Pvi[v][e2][j] + Svii[v][e2][e1] );
						}
					}
				}
			}
		}
	}
}
	// restrição 7
void No::Restricao_TempoMaximoEntreDescarregamentosSeguidosNaMesmaEntrega( TipoAlfa Alfa,TipoTvei Tvei, IloModel& model, int EscreveRestricao ){
	float BigMauternativo;

	for (int v1 = 0; v1 < NV; v1++) {
		for (int v2 = 0; v2 < NV; v2++) {
			for (int e1 = 0; e1 < NE; e1++) {
				if( TCDE[e1] > 1){
					for (int i = 0; i < ( TCDE[e1] - 1 ); i++) {
						if ( EscreveRestricao == 1){
							cout << " - BigM * ( 1 - ALFAvei+1[" << v1 << "][" << e1 << "][" << i + 1 << "] )";
							cout << " + Tvei+1[" << v1 << "][" << e1 << "][" << i + 1 << "] <=";
							cout << " BigM * ( 1 - ALFAv'ei[" <<v2<< "][" <<e1<< "][" <<i<< "] )";
							cout << " + Tv'ei[" << v2 << "][" << e1 << "][" << i << "] + Omega[" << e1 << "]" << endl;
						}
						BigMauternativo = TmaxE[e1] ;			// M7
						model.add( - BigMauternativo * ( 1 - Alfa[v1][e1][i+1] ) +  Tvei[v1][e1][i+1] <=  BigMauternativo * ( 1 - Alfa[v2][e1][i] ) + Tvei[v2][e1][i] + Omega[e1]);
						/* if( v1 == 2 && e1 == 2 && (i + 1) == 2 && v2 == 2 && e1 == 2 && i == 1){
							cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "<< endl;
							cout << " - BigM * ( 1 - Alfa[" <<v1<< "][" <<e1<< "][" <<i + 1<< "]) +  Tvei[" <<v1<< "][" <<e1<< "][" <<i + 1<< "] <=  BigM * ( 1 - Alfa[" <<v2<< "][" <<e1<< "][" <<i<< "]) Tvei[" <<v2<< "][" <<e1<< "][" <<i<< "] + Omega["<<e1<<"]" << endl;
							cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "<< endl;
						} */
					}
				}
			}
		}
	}
}
	// restrição 8
void No::Restricao_TempoMinimoEntreDescarregamentosSeguidosNaMesmaEntrega(TipoAlfa Alfa, TipoTvei Tvei, IloModel& model, int EscreveRestricao ){
    float BigMauternativo;
    for (int v1 = 0; v1 < NV; v1++) {
        for (int v2 = 0; v2 < NV; v2++) {
            for (int e1 = 0; e1 < NE; e1++) {
            	if( TCDE[e1] > 1){
            		for (int i = 0; i < (TCDE[e1] - 1); i++) {
						if ( EscreveRestricao == 1){
							cout << " BigM * ( 1 - ALFAvei+1[" << v1 << "][" << e1 << "][" << i +1 << "]) +";
							cout << " Tvei[" << v1 << "][" << e1 << "][" << i + 1 << "] >= ";
							cout << " Tvei[" << v2 << "][" << e1 << "][" << i << "] +  Pvi[" << v2 << "][" << e1 << "][" << i << "] ";
							cout << "- BigM * ( 1 - ALFAv'ei[" << v2 << "][" << e1 << "][" << i << "] )" << endl;
						}
						BigMauternativo = TmaxE[e1] + Pvi[v2][e1][i];		// M8
						model.add( BigMauternativo  * ( 1 - Alfa[v1][e1][i+1]) + Tvei[v1][e1][i+1] >=   Tvei[v2][e1][i] +   Pvi[v2][e1][i] - BigMauternativo  * ( 1 - Alfa[v2][e1][i]) );
						/*if( v1 == 2 && e1 == 2 && (i + 1) == 2 && v2 == 2 && e1 == 2 && i == 1){
                        cout << " ################################################################ "<< endl;
                        cout << " BigM * ( 1 - Alfa[" << v1 + 1 << "][" <<e1 + 1 << "][" << i + 2 << "]) +  Tvei[" << v1 + 1 << "][" << e1 + 1 << "][" << i + 2 << "] >=  Tvei[" << v2 + 1 << "][" << e1 + 1 << "][" << i + 1 << "] +  Pvi[" << v2 + 1 << "][" << e1 + 1 << "][" << i + 1 << "]  - BigM * ( 1 - Alfa[" <<v2 + 1 << "][" <<e1 + 1 << "][" << i + 1 << "])" << endl;
                        cout << " ################################################################ "<< endl;
                    }*/
            		}
            	}
            }
        }
    }
}
	// restrição 9
void No::Restricao_PrecedenciaTPvei( TipoAlfa Alfa,TipoBeta BetaProducao,TipoTPvei TPvei, IloModel& model, int EscreveRestricao1, int EscreveRestricao2){
	float BigMauternativo;
	int v1Aux;
	int v2Aux;
	int vArmazena;
	for (int e1 = 0; e1 < NE; e1++) {
		for (int i = 0; i < TCDE[e1]; i++) {
			for (int e2 = 0; e2 < NE; e2++) {
				for (int j = 0; j < TCDE[e2]; j++) {
					v1Aux = 0;
					for (int p = 0; p < NP; p++) {
						for (int v1 = 0; v1 < TCVP[p]; v1++) {
							if( v1 == 0 ){
								vArmazena = v1Aux;
							}
							for (int v2 = 0; v2 < TCVP[p]; v2++) {
								if( v2 == 0 ){
									v2Aux = vArmazena;
								}
								if ( i == j and e1 == e2){

								}else{
										if ( EscreveRestricao1 == 1){
											cout << " BigM * ( 1 - ALFAvei[" << v1Aux << "][" << e1 << "][" << i << "] ) ";
											cout << " + BigM * ( 1 - ALFAve'i'[" << v2Aux << "][" << e2 << "][" << j << "] ) ";
											cout << " + BigM * ( 1- BETAProd-veii'[" << p << "][" << e1 << "][" << i << "][" << e2 << "][" << j << "] )";
											cout << " + TPvei'[" << v2Aux << "][" << e2 << "][" << j << "] >=";
											cout << " TPvei[" << v1Aux << "][" << e1 << "][" << i << "] +  TPp[" << p << "] " << endl;
										}
										BigMauternativo = TmaxP[p] + TPp[p];			// M9
										model.add( BigMauternativo  * ( 1 - Alfa[v1Aux][e1][i] ) + BigMauternativo  * ( 1 - Alfa[v2Aux][e2][j] ) + BigMauternativo * ( 1 - BetaProducao[p][e1][i][e2][j] )  + TPvei[v2Aux][e2][j] >= TPvei[v1Aux][e1][i] +  TPp[p] );
										if ( EscreveRestricao2 == 1){
											cout << " BigM * ( 1 - ALFAvei[" << v1Aux << "][" << e1 << "][" << i << "] )";
											cout << " + BigM * ( 1 - ALFAve'i'[" << v2Aux << "][" << e2 << "][" << j << "])";
											cout << " + BigM * BETAProd-veii'[" << p << "][" << e1 << "][" << i << "][" << e2 << "][" << j << "]";
											cout << " + TPvei[" << v1Aux << "][" << e1 << "][" << i << "] >=";
											cout << " TPvei'[" << v2Aux << "][" << e2 << "][" << j << "] + TPp[" << p << "]" << endl;
										}
										BigMauternativo = TmaxP[p] + TPp[p];			// M9
										model.add( BigMauternativo  * ( 1 - Alfa[v1Aux][e1][i]) + BigMauternativo  * ( 1 - Alfa[v2Aux][e2][j]) + BigMauternativo  * BetaProducao[p][e1][i][e2][j]  + TPvei[v1Aux][e1][i] >= TPvei[v2Aux][e2][j] +  TPp[p]);
								}
								v2Aux = v2Aux + 1;
							}
							v1Aux = v1Aux + 1;
						}
					}
				}
			}
		}
	}
}
	// restrição 10
void No::Restricao_TempoDeVidaDoConcreto( TipoAlfa Alfa,TipoTvei Tvei, TipoTPvei TPvei, IloModel& model, int EscreveRestricao){
	float BigMauternativo;
	int vAux;
	vAux = 0;
	for (int p = 0; p < NP; p++) {
		for (int v = 0; v < TCVP[p]; v++) {
			for (int e = 0; e < NE; e++) {
				for (int i = 0; i < TCDE[e]; i++) {
					if ( EscreveRestricao == 1){
						cout << " Tvi[" << vAux << "][" << e << "][" << i << "] - TPvi[" << vAux << "][" << e << "][" << i << "] ";
						cout << " -  BigM * ( 1 - ALFAvei[" << vAux << "][" << e << "][" << i << "] ) <= " << TVC << endl;
					}
					BigMauternativo = TmaxE[e] - TminP[p];
					model.add( Tvei[vAux][e][i] - TPvei[vAux][e][i] - BigMauternativo  * ( 1 - Alfa[vAux][e][i]) <= TVC );
				}
			}
			vAux = vAux + 1;
		}
	}

}
	// restrição 11
void No::Restricao_LimiteDeTempoNaEntrega( TipoTvei Tvei, IloModel& model, int EscreveRestricao){
	for (int v = 0; v < NV; v++) {
		for (int e1 = 0; e1 < NE; e1++) {
			for (int i = 0; i < TCDE[e1]; i++) {
				if ( EscreveRestricao == 1){
					cout << "  Tvei[" << v << "][" << e1 << "][" << i << "] >= TminE[" << e1 <<"]" << endl;
				}
				model.add(  Tvei[v][e1][i] >= TminE[e1] );
				if ( EscreveRestricao == 1){
					cout << "  Tvei[" << v << "][" << e1 << "][" << i << "] <= TmaxE[" << e1 <<"]" << endl;
				}
				model.add(  Tvei[v][e1][i] <= TmaxE[e1] );
			}
		}
	}
}
	// restrição 12
void No::Restricao_LimiteDeTempoNaPlanta( TipoTvei TPvei,  IloModel& model, int EscreveRestricao ){
	int vAux;
	vAux = 0;
	for (int p = 0; p < NP; p++) {
		for (int v = 0; v < TCVP[p]; v++) {
			for (int e1 = 0; e1 < NE; e1++) {
				for (int i = 0; i < TCDE[e1]; i++) {
					if ( EscreveRestricao == 1){
						cout << "  TPvei[" << vAux << "][" << e1 << "][" << i << "] >= TminP[" << p <<"]" << endl;
					}
					model.add(  TPvei[vAux][e1][i] >= TminP[p]);
					if ( EscreveRestricao == 1){
						cout << "  TPvei[" << vAux << "][" << e1 << "][" << i << "] <= TmaxP[" << p <<"]" << endl;
					}
					model.add(  TPvei[vAux][e1][i] <= TmaxP[p]);
				}
			}
			vAux = vAux + 1;
		}
	}
}
	// restrição 13

void No::ForcaSolucaoColocandoRestricoes(string Nome, TipoAlfa Alfa,TipoBeta Beta,TipoTvei Tvei, TipoBeta BetaProducao,TipoTPvei TPvei, IloModel& model){

	if( Nome.compare("p-C101-P1C5-I4-V1.txt") == 0){
		//cout << endl << endl << "Nome : " <<  Nome << endl << endl;



	}

}

// Cria pastas
void No::VerificaOuCriaPastaOut(int EscreveNaTelaResultados){
	DIR* dp1;

	dp1 = opendir ("Out");

	if(!dp1){
		cout <<  "\n\n Nao tem diretorio \"Out\" !!        FUDEU MUITO!! \n" << endl;

		if(system("mkdir Out;") == 0){
			cout << " Criou pasta Out" << endl;
		}else{
			cout << " Problema ao criar pasta Out" << endl;
		}

		/* Outra maneira de criar arquivos

		SituacaoDiretorio = mkdir("./myfolder", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		*/

		dp1 = opendir ("Out");
		if(!dp1){
			cout << "\n Nao tem diretorio  \"InstS\" !!        FUDEU MUITO!! \n" << endl;
		}else{
			cout << " Tem diretorio \"Out\" !!  " << endl;
		}
	}else{
		if( EscreveNaTelaResultados == 1){
			cout << " Tem diretorio \"Out\" !!  " << endl;
		}
	}

	closedir( dp1 );
}
void No::VerificaOuCriaPastaSol(int EscreveNaTelaResultados){
	DIR* dp1;

	dp1 = opendir ("Sol");
	if(!dp1){
		cout <<  "\n\n Nao tem diretorio \"Sol\" !!        FUDEU MUITO!! \n" << endl;

		if(system("mkdir Sol;") == 0){
			cout << " Criou pasta Sol" << endl;
		}else{
			cout << " Problema ao criar pasta Sol" << endl;
		}

		/* Outra maneira de criar arquivos

		SituacaoDiretorio = mkdir("./myfolder", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		*/
		dp1 = opendir ("Sol");
		if(!dp1){
			cout << "\n Nao tem diretorio  \"Sol\" !!        FUDEU MUITO!! \n" << endl;
		}else{
			cout << " Tem diretorio \"Sol\" !!  " << endl;
		}
	}else{
		if( EscreveNaTelaResultados == 1){
			cout << " Tem diretorio \"Sol\" !!  " << endl;
		}
	}
	closedir( dp1 );
}

// Escreve variáveis
void No::EscreveVariaveisAlfaDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex, TipoAlfa Alfa){
	for (int v = 0; v< NV; v++) {
		if( EscreveArquivoComRespostas == 1){
			logfile2 << " Veiculo " << v << endl;
		}
		if( EscreveNaTelaResultados == 1){
			cout << " Veiculo " << v << endl;
		}
		for (int e = 0; e < NE; e++) {
			for( int i = 0; i < TCDE[e]; i++){
				if( EscreveNaTelaResultados == 1){
					cout << Alfa[v][e][i].getName() << " [" << cplex.getValue(Alfa[v][e][i]) << "]  ";
				}
				if( EscreveArquivoComRespostas == 1){
					logfile2 << Alfa[v][e][i].getName() << " [" << cplex.getValue(Alfa[v][e][i]) << "]  ";
				}
			}
			if( EscreveNaTelaResultados == 1){
				cout << endl;
			}
			if( EscreveArquivoComRespostas == 1){
				logfile2 << endl;
			}
		}
	}
}
void No::EscreveVariaveisBetaDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex,  TipoBeta Beta ){
	for (int v = 0; v< NV; v++) {
		if( EscreveNaTelaResultados == 1){
			cout << " Veiculo " << v << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << " Veiculo " << v << endl;
		}
		for (int e1 = 0; e1 < NE; e1++) {
			for( int i = 0; i < TCDE[e1]; i++){
				for (int e2 = 0; e2 < NE; e2++) {
					for( int j = 0; j < TCDE[e2]; j++){
						if( e1 == e2 and i == j){

						}else{
							if( EscreveNaTelaResultados == 1){
								cout << Beta[v][e1][i][e2][j].getName();
								cout << " [" << cplex.getValue(Beta[v][e1][i][e2][j]) << "]  ";
								cout << endl;
							}
							if( EscreveArquivoComRespostas == 1){
								logfile2 << Beta[v][e1][i][e2][j].getName();
								logfile2 << " [" << cplex.getValue(Beta[v][e1][i][e2][j]);
								logfile2 << "]  " << endl;
							}
						}
					}
				}
			}
		}
		if( EscreveNaTelaResultados == 1 ){
			cout << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << endl;
		}
	}
}
void No::EscreveVariaveisBetaProducaoDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex,  TipoBeta BetaProducao ){
	for (int p = 0; p < NP; p++) {
		if( EscreveNaTelaResultados == 1){
			cout << " Planta " << p << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << " Planta " << p << endl;
		}
		for (int e1 = 0; e1 < NE; e1++) {
			for( int i = 0; i < TCDE[e1]; i++){
				for (int e2 = 0; e2 < NE; e2++) {
					for( int j = 0; j < TCDE[e2]; j++){
						if( e1 == e2 and i == j){

						}else{
							if( EscreveNaTelaResultados == 1){
								cout << BetaProducao[p][e1][i][e2][j].getName();
								cout << " [" << cplex.getValue(BetaProducao[p][e1][i][e2][j]) << "]  ";
								cout << endl;
							}
							if( EscreveArquivoComRespostas == 1){
								logfile2 << BetaProducao[p][e1][i][e2][j].getName();
								logfile2 << " [" << cplex.getValue(BetaProducao[p][e1][i][e2][j]) << "]  ";
								logfile2 << endl;
							}
						}
					}
				}
			}
		}
		if( EscreveNaTelaResultados == 1 ){
			cout << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << endl;
		}
	}
}
void No::EscreveVariaveisTveiDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex, TipoTvei Tvei){
	for (int v = 0; v < NV; v++) {
		if( EscreveArquivoComRespostas == 1){
			logfile2 << " Veiculo " << v << endl;
		}
		if( EscreveNaTelaResultados == 1){
			cout << " Veiculo " << v << endl;
		}
		for (int e = 0; e < NE; e++) {
			for( int i = 0; i < TCDE[e]; i++){
				if( EscreveNaTelaResultados == 1){
					cout << Tvei[v][e][i].getName() << " [" << cplex.getValue(Tvei[v][e][i]) << "]  " << endl;
				}
				if( EscreveArquivoComRespostas == 1){
					logfile2 << Tvei[v][e][i].getName() << " [" << cplex.getValue(Tvei[v][e][i]) << "]  " << endl;
				}
			}
		}
		if( EscreveNaTelaResultados == 1){
			cout << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << endl;
		}
	}
}
void No::EscreveVariaveisTPveiDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex, TipoTPvei TPvei ){
	int vAux;
	vAux = 0;
	for (int p = 0; p < NP; p++) {
		if( EscreveNaTelaResultados == 1){
			cout << "  Planta " << p << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << "  Planta " << p << endl;
		}
		for (int v = 0; v < TCVP[p]; v++) {
			for (int e = 0; e < NE; e++) {
				for( int i = 0; i < TCDE[e]; i++){
					if( EscreveNaTelaResultados == 1){
						cout << TPvei[vAux][e][i].getName() << " [" << cplex.getValue(TPvei[vAux][e][i])  << "]  "<< endl;
					}
					if( EscreveArquivoComRespostas == 1){
						logfile2 << TPvei[vAux][e][i].getName() << " [" << cplex.getValue(TPvei[vAux][e][i]) << "]  "<< endl;
					}
				}
			}
			vAux = vAux + 1;
		}
		if( EscreveNaTelaResultados == 1){
			cout << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << endl;
		}
	}
}
void No::EscreveVariaveisZeDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex, IloFloatVarArray Ze ){
	for (int e = 0; e < NE; e++) {
		for( int i = 0; i < TCDE[e]; i++){
			if( EscreveNaTelaResultados == 1){
				cout << Ze[e].getName() << " [" << cplex.getValue(Ze[e]) << "]  "<< endl;
			}
			if( EscreveArquivoComRespostas == 1){
				logfile2 << Ze[e].getName() << " [" << cplex.getValue(Ze[e]) << "]  "<< endl;
			}
		}
	}

	if( EscreveNaTelaResultados == 1){
		cout << endl;
	}
	if( EscreveArquivoComRespostas == 1){
		logfile2 << endl;
	}

}
void No::EscreveVariaveisZrDoModeloAposResolucao(int EscreveArquivoComRespostas, int EscreveNaTelaResultados,ofstream& logfile2, IloCplex cplex, IloFloatVarArray Zr ){
	for (int p = 0; p < NP; p++) {
		if( EscreveNaTelaResultados == 1){
			cout << Zr[p].getName() << " [" << cplex.getValue(Zr[p]) << "]  "<< endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << Zr[p].getName() << " [" << cplex.getValue(Zr[p]) << "]  "<< endl;
		}
	}

	if( EscreveNaTelaResultados == 1){
		cout << endl;
	}
	if( EscreveArquivoComRespostas == 1){
		logfile2 << endl;
	}
}



// Escreve a Solução
void No::EscreveItinerarioVeiculos( int EscreveNaTelaResultados,int EscreveArquivoComRespostas, ofstream& logfile2, IloCplex cplex, TipoAlfa Alfa, TipoTvei Tvei, TipoTPvei TPvei){
	int vAux;

	vAux = 0;
	for (int p = 0; p < NP; p++) {
		if( EscreveNaTelaResultados == 1){
			cout << "     Planta " << p + 1 << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << "     Planta " << p + 1 << endl;
		}
		for (int v = 0; v < TCVP[p]; v++) {
			if( EscreveNaTelaResultados == 1){
				cout << " Veiculo " << vAux + 1 << endl;
			}
			if( EscreveArquivoComRespostas == 1){
				logfile2 << " Veiculo " << vAux + 1 << " : "<< endl;
			}
			for (int e = 0; e < NE; e++) {
				for( int i = 0; i < TCDE[e]; i++){
					if( 0.9 < cplex.getValue(Alfa[vAux][e][i]) && cplex.getValue(Alfa[vAux][e][i]) < 1.1){
						if( EscreveNaTelaResultados == 1){
							cout << '\t' << " Entrega[Construcao->" << e+1 << "][Job->" << i+1<< "] carrega as ";
							printf("%.2f", cplex.getValue(TPvei[vAux][e][i]) );
							cout << ", sai da planta as ";
							printf("%.2f", ( cplex.getValue(TPvei[vAux][e][i]) + TPp[p] ) );
							cout << ", chega a entrega" << e + 1 << " as " ;
							printf("%.2f", cplex.getValue(Tvei[vAux][e][i]) );
							cout << " e sai as  ";
							printf("%.2f", ( cplex.getValue(Tvei[vAux][e][i]) + Pvi[vAux][e][i]) );
							cout << ", retorna a planta as ";
							printf("%.2f", ( cplex.getValue(Tvei[vAux][e][i]) + Pvi[vAux][e][i] + Dep[e][p] ) );
							cout << endl;
						}
						if( EscreveArquivoComRespostas == 1){
							logfile2 << '\t' << " Entrega[Construcao->" << e+1 << "][Job->" << i+1<< "] carrega as ";
							logfile2 <<  cplex.getValue(TPvei[vAux][e][i]) ;
							logfile2  << ", sai da planta as " << cplex.getValue(TPvei[vAux][e][i]) + TPp[p] ;
							logfile2 << ", chega a entrega" << e + 1 << " as " << cplex.getValue(Tvei[vAux][e][i]);
							logfile2 << " e sai as  " << cplex.getValue(Tvei[vAux][e][i]) + Pvi[vAux][e][i] ;
							logfile2 << ", retorna a planta as " << cplex.getValue(Tvei[vAux][e][i]) + Pvi[vAux][e][i] + Dep[e][p];
							logfile2 << endl;
						}
					}
				}
			}
			vAux = vAux + 1;
		}
	}
}
void No::EscreveEntregasNosClientes(int EscreveNaTelaResultados,int EscreveArquivoComRespostas, ofstream& logfile2, IloCplex cplex, TipoAlfa Alfa, TipoTvei Tvei){
	int vAux;
	if( EscreveNaTelaResultados == 1){
		cout << endl << endl;
		cout << "           Tempo de entrega em cada cliente         " << endl;
	}

	if( EscreveArquivoComRespostas == 1){
		logfile2 << endl << endl;
		logfile2 <<  "           Tempo de entrega em cada cliente         " << endl;
	}
	for (int e = 0; e < NE; e++) {
		if( EscreveNaTelaResultados == 1){
			cout << " Cliente " << e +1 << "\t[ ";
			printf("%.2f", TminE[e]);
			cout << "\t<=\t";
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << " Cliente " << e +1 << "\t[ ";
			logfile2 << TminE[e];
			logfile2 << "\t<=\t";
		}
		for( int i = 0; i < TCDE[e]; i++){
			vAux = 0;
			for (int p = 0; p < NP; p++) {
				for (int v = 0; v < TCVP[p]; v++) {
					if( 0.9 < cplex.getValue(Alfa[vAux][e][i]) && cplex.getValue(Alfa[vAux][e][i]) < 1.1 ){
						//cout << "   Tvei[" << vAux << "][" << e << "][" << i <<"] " << TveiImprime[vAux][e][i];
						if( EscreveNaTelaResultados == 1){
							cout << "\t";
							printf("%.2f", cplex.getValue(Tvei[vAux][e][i]) );
							cout << "[v" << vAux + 1<< "]";
						}
						if( EscreveArquivoComRespostas == 1){
							logfile2 << "\t";
							logfile2 << cplex.getValue(Tvei[vAux][e][i]);
							logfile2 << "(v[" << vAux + 1<< "] e[" << e + 1 << "] i[" << i + 1 << "] )";
						}
					}
					vAux++;
				}

			}
		}
		if( EscreveNaTelaResultados == 1){
			cout << "\t<=\t";
			printf("%.2f", TmaxE[e]);
			cout << "]" << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << "\t<=\t";
			logfile2 << TmaxE[e];
			logfile2 << "]" << endl;
		}
	}
}
void No::EscreveUtilizacaoVeiculos(int EscreveNaTelaResultados,int EscreveArquivoComRespostas, ofstream& logfile2, IloCplex cplex, TipoAlfa Alfa, TipoTvei Tvei){
	int vAux;
	int UsouCaminhao;
	int AtendeCliente;
	int AtendendoCliente;


	if( EscreveNaTelaResultados == 1){
		cout << endl << endl;
		cout << "           Veiculos usados         " << endl;
	}
	if( EscreveArquivoComRespostas == 1){
		logfile2 << endl << endl;
		logfile2 << "           Veiculos usados         " << endl;
	}
	vAux = 0;
	for (int p = 0; p < NP; p++) {
		if( EscreveNaTelaResultados == 1){
			cout << "Planta " << p + 1 << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << "Planta " << p + 1 << endl;
		}
		for (int v = 0; v < TCVP[p]; v++) {
			UsouCaminhao = 0;
			for (int e = 0; e < NE; e++) {
				for( int i = 0; i < TCDE[e]; i++){
					if( 0.9 < cplex.getValue(Alfa[vAux][e][i]) && cplex.getValue(Alfa[vAux][e][i]) < 1.1 ){
						UsouCaminhao = 1;
					}
				}
			}
			if( UsouCaminhao == 1){
				if( EscreveNaTelaResultados == 1){
					cout << "  Veiculo " << vAux + 1 << " \t[clientes ->\t";
				}
				if( EscreveArquivoComRespostas == 1){
					logfile2  << "  Veiculo " << vAux + 1 << " \t[clientes ->\t";
				}
				for (int e = 0; e < NE; e++) {
					AtendeCliente = 0;
					AtendendoCliente = 0;
					for( int i = 0; i < TCDE[e]; i++){
						if( 0.9 < cplex.getValue(Alfa[vAux][e][i]) && cplex.getValue(Alfa[vAux][e][i]) < 1.1  ){
							AtendeCliente = AtendeCliente + 1;
							AtendendoCliente = 1;
						}
						if( AtendeCliente == 1 && AtendendoCliente == 1){
							if( EscreveNaTelaResultados == 1){
								cout << "   " << e + 1 ;
							}
							if( EscreveArquivoComRespostas == 1){
								logfile2 << "   " <<  e + 1 << " ";
							}
						}
						if(AtendendoCliente == 1){
							if( EscreveNaTelaResultados == 1){
								cout << "(" << cplex.getValue(Tvei[vAux][e][i]) << ") ";
							}
							if( EscreveArquivoComRespostas == 1){
								logfile2 << "(" << cplex.getValue(Tvei[vAux][e][i]) << ") ";
							}
							AtendendoCliente = 0;
						}

					}
				}
				if( EscreveNaTelaResultados == 1){
					cout << "]" << endl;
				}
				if( EscreveArquivoComRespostas == 1){
					logfile2  << "]" << endl;
				}
			}
			vAux++;
		}
		if( EscreveNaTelaResultados == 1){
			cout << endl;
		}
		if( EscreveArquivoComRespostas == 1){
			logfile2 << endl;
		}
	}
}

// Resolve modelo
int No::Cplex(string Nome, int TempoMaximo, int &status, float &primal, float &dual,  float &gap, float &tempo){

	int Escreve;				// Escreve variaveis criadas

	int EscreveVariaveis;
	int OutPut1;
	int OutPut2;
	int SaidaPastaSeparada;
	int EscreveArquivoComRespostas;
	int EscreveNaTelaResultados;
	vector < int > EscreveRestricao;
	EscreveRestricao.resize(20+1);
	for( int i = 0; i <= 20; i++){
		EscreveRestricao[i] = 0;
	}

	vector < int > TamanhoPenalidade;
	TamanhoPenalidade.resize(2+1);
	for( int i = 0; i <= 2; i++){
		TamanhoPenalidade[i] = 2;
	}

	Escreve = 0;				// Escreve as variaveis criadas
	EscreveVariaveis = 1;
	OutPut1 = 1;
	OutPut2 = 1;
	SaidaPastaSeparada = 1;
	EscreveArquivoComRespostas = 1;
	EscreveNaTelaResultados = 0;

// Começa a escrever modelo do Cplex
	IloModel 	model(env);

/* Declara variaveis */

// Variavel ALFA
	TipoAlfa 	Alfa(env, NV);
	CriaAlfa(Alfa,Escreve);

// Variavel BETA
	TipoBeta 	Beta(env, NV);
	CriaBeta(Beta,Escreve);

// Variavel BETAProducao
	TipoBeta 	BetaProducao(env, NV);
	CriaBetaProducao(BetaProducao,Escreve);


// Variavel Ze
	TipoZe 		Ze(env,NE);
	CriaZe(Ze ,Escreve);

// Variavel Zr
	TipoZr 		Zr(env,NP);
	CriaZr(Zr ,Escreve);

// Variavel Tvei
	TipoTvei 	Tvei(env,NV);
	CriaTvei( Tvei, Escreve);

// Variavel TPvei
	TipoTPvei 	TPvei(env,NV);
	CriaTPvei( TPvei, Escreve);

// Variaveis de adiantamento e postergamento dos limites de tempo




// Funcao Objetivo
	FuncaoObjetivo(Ze, Zr, model, EscreveRestricao[0]);

// Restrição 1 : Antendimento das Demandas
	Restricao_AtendimentoDasDemandas(Alfa, model, EscreveRestricao[1]);
// Restrição  2 : Lower bound Ze
	Restricao_LowerBoundZe(Ze, Tvei, Alfa, model);
// Restrição  3 : Vinculo Tvei e TPvei
	Restricao_VinculoTveiTPvei( Alfa, TPvei, Tvei,model, EscreveRestricao[3] );
// Restrição  4 : de lower bound Zr
	Restricao_LowerBoundZr( Zr, Tvei, Alfa, model, EscreveRestricao[4]);
// Restrição  5 e 6 : de precedencia Tvei
	Restricao_PrecedenciaTvei(  Alfa, Beta, Tvei, model,  EscreveRestricao[5], EscreveRestricao[6]);
// Restrição  7:
	Restricao_TempoMaximoEntreDescarregamentosSeguidosNaMesmaEntrega( Alfa, Tvei, model, EscreveRestricao[7] );
// Restrição 8
    Restricao_TempoMinimoEntreDescarregamentosSeguidosNaMesmaEntrega( Alfa, Tvei, model, EscreveRestricao[10] );
// Restrição 9
    Restricao_PrecedenciaTPvei( Alfa, BetaProducao, TPvei, model, EscreveRestricao[11],EscreveRestricao[12]);
// Restrição 10
    Restricao_TempoDeVidaDoConcreto( Alfa,Tvei,TPvei, model,EscreveRestricao[13]);
// Restrição  11
	Restricao_LimiteDeTempoNaEntrega( Tvei,  model, EscreveRestricao[14] );
// Restrição  12
	Restricao_LimiteDeTempoNaPlanta(  TPvei,  model, EscreveRestricao[15] );



// força a solução a ser como eu quero atravez da implementação de certas restrições
	ForcaSolucaoColocandoRestricoes( Nome, Alfa, Beta, Tvei, BetaProducao, TPvei, model);



// Modelo
	IloCplex *cplex;

	cplex = new IloCplex(model);
	//cplex.exportModel("model.lp");

// Cria pasta OUT
	VerificaOuCriaPastaOut(EscreveNaTelaResultados);

	Nome1 = "./Out/";
	Nome1 += Nome;

	//cout << endl << endl << " arquivo a gravar a saida " << c1 << endl << endl;

	ofstream logfile1(Nome1.c_str());

	if(SaidaPastaSeparada == 1){
		cplex->setOut(logfile1);
	}
	cplex->setParam(IloCplex::TiLim, TempoMaximo);
	cplex->setParam(IloCplex::Threads, 1);			// com uma tread ele coloca os nos com mais sentido e chega ao 0% de gap




	cplex->setParam(IloCplex::Param::MIP::Interval, 1);			// de quantos nos da arvore de branch se quer imprimir no log, se coloca 1 se imprime todos.
	cplex->setParam(IloCplex::EpGap, 0.00000001);			// se coloca o gap relativo que se quer.
	cplex->setParam(IloCplex::Param::Tune::Display,3);			// o 1 é o defalt

	//cplex->setParam(IloCplex::Param::MIP::Display,2);   // fornece os dados por no





	Tempo1 = cplex->getCplexTime();

	//cout << endl << " setou tempo" << endl << endl;
	primal = -1;
	dual = -1;
	gap = -1;

// Resolve o modelo.
	if (!cplex->solve()) {
		cerr << "Failed to optimize LP." << endl;
		status = cplex->getStatus();
		cout << " status = (" << status << ")" << endl;
		tempo = cplex->getCplexTime() - Tempo1;
		//cout << "  \n\n galo1 \n\n" ;
		logfile1.close();
		//throw(-1);                                                   // Olhar!!!!!!!!!!!!!!!!!!

		//cout << "  \n\n galo2 \n\n" ;

		//model.end();				// problema, trava o programa. olhar! falam que demora muito. que é melhor deletar o objeto IloClpex

		delete(cplex);

		Alfa.clear();
		Beta.clear();
		BetaProducao.clear();
		Ze.clear();
		Zr.clear();
		Tvei.clear();
		TPvei.clear();
		TPvei.clear();
		EscreveRestricao.clear();


		//cout << "  \n\n galo3 \n\n" ;

		return (0);
	}else{

		//cout << endl << " rodou " << endl << endl;

		Tempo2 = cplex->getCplexTime();

		VerificaOuCriaPastaSol(EscreveNaTelaResultados);

		Nome2 = "./Sol/";
		Nome2 += Nome;

		//cout << endl << endl << " arquivo a gravar a solucao " << Nome2 << endl << endl;

		ofstream logfile2(Nome2.c_str());

		status = cplex->getStatus();
		primal = cplex->getObjValue();
		dual = cplex->getBestObjValue();

		gap =  100 * ( cplex->getObjValue() - cplex->getBestObjValue() ) / cplex->getObjValue();
		tempo = Tempo2 - Tempo1;

		if( EscreveNaTelaResultados == 1){
			cout << "Solution status = " << status << " [" << cplex->getStatus() << "] "<< endl;
			cout << "Solution primal cost = " << primal << endl;
			cout << "Solution dual cost = " << dual << endl ;
			cout << "Gap = " << gap << "%" << endl ;
			cout << "Tempo = " << tempo << " segundos. " << endl<< endl;
		}

		if( EscreveArquivoComRespostas == 1){
			logfile2 <<  "Solution status = " << " [" << cplex->getStatus() << "] "<< endl;
			logfile2 << "Solution primal cost = " << primal << endl;
			logfile2 << "Solution dual cost = " << dual << endl ;
			logfile2 << "Gap = " << gap  << "%" << endl ;
			logfile2 << "Tempo = " << tempo << " segundos. " << endl << endl;
		}

		if( EscreveVariaveis == 1){
	// Imprimi Variaveis
			EscreveVariaveisAlfaDoModeloAposResolucao(			EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, Alfa);
			EscreveVariaveisBetaDoModeloAposResolucao(			EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, Beta);
			EscreveVariaveisBetaProducaoDoModeloAposResolucao(	EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, BetaProducao);
			EscreveVariaveisTveiDoModeloAposResolucao(			EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, Tvei);
			EscreveVariaveisTPveiDoModeloAposResolucao(			EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, TPvei);
			EscreveVariaveisZeDoModeloAposResolucao(			EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, Ze);
			EscreveVariaveisZrDoModeloAposResolucao(			EscreveArquivoComRespostas, EscreveNaTelaResultados, logfile2, *cplex, Zr);

		}

		if( OutPut1 == 1){
	// Itinerario dos veiculos
			EscreveItinerarioVeiculos( EscreveNaTelaResultados, EscreveArquivoComRespostas, logfile2, *cplex, Alfa,  Tvei, TPvei);
		}

		if( OutPut2 == 1){
	// Tempo de cada entrega em cada cliente
			EscreveEntregasNosClientes(EscreveNaTelaResultados,EscreveArquivoComRespostas, logfile2, *cplex, Alfa,  Tvei);
	// Veiculos usados
			EscreveUtilizacaoVeiculos( EscreveNaTelaResultados,EscreveArquivoComRespostas, logfile2, *cplex, Alfa,  Tvei);
		}

		logfile1.close();
		logfile2.close();

		//model.end();				// problema, trava o programa. olhar! falam que demora muito. que é melhor deletar o objeto IloClpex

		delete(cplex);

		Alfa.clear();
		Beta.clear();
		BetaProducao.clear();
		Ze.clear();
		Zr.clear();
		Tvei.clear();
		TPvei.clear();
		TPvei.clear();
		EscreveRestricao.clear();



		return (1);
	}
}

No::~No(){


	TCVP.clear();
	CVP.clear();
	TCDE.clear();
	CDE.clear();
	Dpe.clear();
	Dep.clear();
	Pvi.clear();
	TPp.clear();
	Omega.clear();
	Svii.clear();
	TminE.clear();
	TmaxE.clear();
	TminP.clear();
	TmaxP.clear();
	Pvi.clear();
	Omega.clear();
	Svii.clear();
	TminE.clear();
	TmaxE.clear();
	TminP.clear();
	TmaxP.clear();
	Nome1.clear();
	Nome2.clear();

	env.end();


}

#endif /* MODELO_HPP_ */
