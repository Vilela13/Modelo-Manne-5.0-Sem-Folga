#include "Biblioteca.hpp"


int main(int argc, char **argv) {


	if( argc == 4){

		list<string> ListaInstancias;
		string Nome;


		int EscreveDadosLidosNaTela;

		list<string>::iterator it;

		//ofstream ArquivoExcelResposta;
		FILE *ArquivoExcelResposta;

// Exscrever a dadta
		time_t timer;
		char buffer[26];
		struct tm* tm_info;

// Variavel que indica se resolveu
		int resolveu;

// Status da solução
		int Status;
		double SolucaoPrimal;
		double SolucaoDual;
		double Gap;
		double Tempo;
		EscreveDadosLidosNaTela = 0;



		string TipoDeEntrada;
		string Instancias;

		ifstream ArquivoInstancia;

		string Saida;

		No *Instancia;

		int TempoExecucao;



	//Cria instancia manual
	    //No PreInstancia;

//Cria instância que criei na mão
		//PreInstancia.PreencheEstrutura();
		//PreInstancia.CriaTXT();


	// Resolve o problema

		TipoDeEntrada = argv[1];
		Instancias = argv[2];
		TempoExecucao = atoi( argv[3] ) ;

		//cout << "   Tempo = " << TempoExecucao << " " << endl;


		if( TipoDeEntrada.compare(0,3,"arq") == 0 ){
			ArquivoInstancia.open(Instancias.c_str());
			if ( ArquivoInstancia.is_open() ){
				ArquivoInstancia >> Nome;
				while( Nome != "EOF"){
					//cout << " coloca lista = " << Nome  << endl ;
					ListaInstancias.push_back(Nome);
					ArquivoInstancia >> Nome;

				}
				ArquivoInstancia.close();
			}
		}else{
			if( TipoDeEntrada.compare(0,4,"inst") == 0 ){
				ListaInstancias.push_back(Instancias);
			}else{
				cout << "(" << TipoDeEntrada << ")";
				printf( " TipoDeEntrada  Problema na definição da entrada das instancias. \n\n\n");
				ListaInstancias.clear();
				Nome.clear();
				Instancias.clear();
				Saida.clear();
				return 0;
			}
		}


		// ----------- Le um arquivo com as instancias a serem resolvidas pelo modelo, abre o arquivo com a instancia e o resolve -------------------------- //

			//cout << endl << endl << " Lendo arquivo " << endl << endl << endl;


		Saida = "R-";				// coloca Res- no char*
		if( TipoDeEntrada.compare(0,3,"arq") == 0 ){
			Saida += Instancias;
		}else{
			Saida += "Instancias.txt";
		}
		//Saida += ".txt";

		//cout << " Saida = > "<< Saida << "   Tamanho entrada = " << TamanhoEntrda << endl;

		//ArquivoExcelResposta.open(Saida.c_str());
		ArquivoExcelResposta = fopen(Saida.c_str(), "a");

		//ArquivoExcelResposta << " Instância" << '\t';
		//ArquivoExcelResposta << " Status" << '\t';
		//ArquivoExcelResposta << " Solução Primal" << '\t';
		//ArquivoExcelResposta << " Solução Dual" << '\t';
		//ArquivoExcelResposta << " Gap" << '\t';
		//ArquivoExcelResposta << " Tempo" << '\n';

		time(&timer);
		tm_info = localtime(&timer);
		strftime(buffer, 26, " * %H:%M:%S de %d:%m:%Y", tm_info);

		if( TipoDeEntrada.compare("arq") == 0 ){
			fprintf(ArquivoExcelResposta,"%s \n", buffer);
			fprintf(ArquivoExcelResposta, "Instância \t Status \t Solução_Primal \t Solução_Dual \t Gap \t Tempo \n");
		}
		fclose(ArquivoExcelResposta);


		while( !ListaInstancias.empty()){
			Instancia = new No;
			it = ListaInstancias.begin();
			Nome = *it;
			ListaInstancias.pop_front();
			cout << " Modelo <= " << Nome << endl ;

			if( Instancia->LeDados(Nome, EscreveDadosLidosNaTela) == 1){

				resolveu = Instancia->Cplex(Nome, TempoExecucao, Status, SolucaoPrimal, SolucaoDual,  Gap, Tempo);
				cout  << " Resolveu = " << resolveu << endl << endl ;

				ArquivoExcelResposta = fopen(Saida.c_str(), "a");
				fprintf(ArquivoExcelResposta, " %s \t", Nome.c_str());
				//ArquivoExcelResposta << Nome  << '\t' ;

				switch (Status){
					//case 0:	ArquivoExcelResposta <<  "Unknow" << '\t';						break;
					case 0:	fprintf(ArquivoExcelResposta, "Unknow \t");						break;
					//case 1:	ArquivoExcelResposta <<  "Feasible" << '\t';					break;
					case 1:	fprintf(ArquivoExcelResposta, "Feasible \t");						break;
					//case 2:	ArquivoExcelResposta <<  "Optimal" << '\t';						break;
					case 2:	fprintf(ArquivoExcelResposta, "Optimal \t");						break;
					//case 3:	ArquivoExcelResposta <<  "Infeasible" << '\t';					break;
					case 3:	fprintf(ArquivoExcelResposta, "Infeasible \t");						break;
					//case 4:	ArquivoExcelResposta <<  "Unbounded" << '\t';					break;
					case 4:	fprintf(ArquivoExcelResposta, "Unbounded \t");						break;
					//case 5: ArquivoExcelResposta <<  "Infeasible Or Unbounded" << '\t';		break;
					case 5:	fprintf(ArquivoExcelResposta, "Infeasible Or Unbounded \t");						break;
					//default: ArquivoExcelResposta <<  "Erro" << '\t';
					default: fprintf(ArquivoExcelResposta, "Erro \t");
				}
				//ArquivoExcelResposta << " " <<   SolucaoPrimal << '\t' <<  " " << SolucaoDual << '\t' << " " <<   Gap << '\t' <<  " " << Tempo << '\n';
				fprintf(ArquivoExcelResposta, "%.3f \t %.3f \t %.3f \t %.3f \t \n", SolucaoPrimal, SolucaoDual, Gap, Tempo);
				fclose(ArquivoExcelResposta);

			}
			//cout << endl << " Antes do delete " << Nome <<  endl;

			delete(Instancia);
			//cout << endl << " Depois do delete "  << Nome << endl;
		}

		//ArquivoExcelResposta.close();

		cout << " \n Acabou! Galo Doido! \n";

		ListaInstancias.clear();
		Nome.clear();
		Instancias.clear();
		Saida.clear();

		return 1;

	}else{
		cout << "\n \n Passagem de parametros errada \n \n";
		return 0;
	}

}
