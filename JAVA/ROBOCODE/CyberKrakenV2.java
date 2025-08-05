package competicao; //Pasta onde está o arquivo CyberKrakenV2.java, chamada 'competicao'

import robocode.*; //Importação do Robocode para uso de funções, classes e métodos próprios do software
import java.awt.Color; //Importação do Java para uso de cores
import robocode.util.*; //Importação do Robocode para utilização de operações matemáticas avançadas

// API help : https://robocode.sourceforge.io/docs/robocode/robocode/Robot.html

/**
 * CyberKrakenV2 - a robot by Bruno Antonello, Filipe Gustavo Paganoto, Marvin Cristhian Gomes Pinto; 3ºano Desenvolvimento de Sistemas  -  2024
 * 
 * CyberKrakenV2: Um robô da classe RateControlRobot, que persegue o adversário e esquiva de ataques, com intuito ofensivo (ataque) e tático.
 */
public class CyberKrakenV2 extends RateControlRobot{
    //Variáveis  
    double Distance, EnemyX, EnemyY, Position, Vel, X, Y;
    boolean Escape;

	public void run() {
      	// Initialization of the robot should be put here
        //Cores de CyberKraken
            setBodyColor(Color.black); //cor do corpo do robô (Preto)
			setRadarColor(new Color(245, 17, 17)); //cor do radar do robô (Vermelho)
			setGunColor(new Color(7, 38, 219)); //cor da arma do robô (Azul)
			setScanColor(new Color(212, 25, 25)); //cor do scanner do robô (Vermelho)
			
    // Função para ajustar algumas partes da estrutura com outras ao decorrer do movimento
	    setAdjustRadarForRobotTurn(true); 
        setAdjustGunForRobotTurn(true);
        setAdjustRadarForGunTurn(true);	  
		
    //Mensagem inicial
	System.out.println("Se quiser ser rei, vai ter que me passar!");
   
     //Enquanto verdadeiro (loop - repetição)
		while(true) {	
		    // O radar rotaciona com objetivo de encontrar o adversário
            turnRadarRight(360);
		}
	}

	
	 //onScannedRobot: Quando identificar um robô no scanner
	public void onScannedRobot(ScannedRobotEvent e) {		 
       //e.: prefixo utilizado para se referir ao inimigo (em relação ao adversário).
      //fire: tiro, sua potência/valor subtrai a energia do robô.
     //getEnergy(): compara a energia do robô.
    //getBearing(): retorna o ângulo em graus do robô.
   //getHeading(): retorna o ângulo em graus atual da cabeça do robô, sabendo assim aonde ele está apontando. 
  //getDistance(): retorna a distância do robô em pixels.
 //O uso de 'Radians' em algumas funções se faz necessária para o uso de valores em radianos, não em graus. Assim permitindo cálculos precisos, e segundo o
//conceito matemático: 180° / π (PI) = rad (1 radiano).

         //Regula a velocidade do robô
         setVelocityRate(20);
         //Faz o cálculo do ângulo absoluto do inimigo, somando o ângulo de orientação (adversário) e da cabeça (nosso robô) em radianos
         Distance = e.getBearingRadians() + getHeadingRadians();
		 //Calcula a coordenada X somada à distância do adversário multiplicada pelo seno do ângulo absoluto, com intuito de saber a posição em X do adversário
         EnemyX = getX() + e.getDistance() * Math.sin(Distance);
         //Calcula a coordenada Y somada à distância do adversário multiplicada pelo cosseno do ângulo absoluto, com intuito de saber a posição em Y do adversário
         EnemyY = getY() + e.getDistance() * Math.cos(Distance);
		 //Identifica a posição atual do inimigo em radianos
         Position = e.getHeadingRadians();
         //Obtêm a velocidade do adversário
         Vel = e.getVelocity();
		 //Valor atribuido de EnemyX
         X = EnemyX; 
		 //Valor atribuido de EnemyY
         Y = EnemyY;
        //Atualiza o local do inimigo em X, de acordo com sua posição e velocidade (com incrementação)
        X += Math.sin(Position) * Vel;
		//Atualiza o local do inimigo em Y, de acordo com sua posição e velocidade (com incrementação)
        Y += Math.cos(Position) * Vel;
        
        //Ângulo para mirar no inimigo (alta precisão)
		//Obtém o ângulo absoluto, através do Math.atan2, que analisa a diferença entre o X do adversário e o X do nosso robô, sendo a mesma lógica para o eixo Y.
        double Angle = Utils.normalAbsoluteAngle(Math.atan2(X - getX(), Y - getY()));
		//Direção que o canhão deverá apontar, sendo a diferença entre o ângulo absoluto (Angle) pela direção a qual o canhão está mirando (getGunHeadingRadians())
		double Direction = Angle - getGunHeadingRadians(); //Mira na direção do inimigo
		 
        // Faz o radar girar na direção do inimigo, com precisão 
        setTurnRadarRightRadians(Utils.normalRelativeAngle(Distance - getRadarHeadingRadians())); //Cálculo da posição do radar e da posição aproximada do  adversário
       //Faz o canhão mirar no inimigo, com precisão
        setTurnGunRightRadians(Utils.normalRelativeAngle(Direction));

       //Se a distância até o adversário for maior que 200 e o boolean Escape for verdadeiro (levou tiro), esquivará
        if (e.getDistance() > 200 && Escape){
        setTurnRightRadians(Distance / 4 * - 1 - getRadarHeadingRadians());  
        setTurnLeft(e.getBearing());
		//Define como false, para não ser executado de novo, até não receber outro tiro
        Escape = false;
         }else{
        //Vai para frente de acordo com a distância até o inimigo (mais distante = mais para frente) dividido por 2
	     setAhead(e.getDistance() / 2);
        //Define como false, para não ser executado quando a distância for maior que a desejada (200px), até não receber outro tiro
         Escape = false;
         }
		 
		 //A distância até o inimigo se faz necessária para saber quando o robô deverá voltar a esquivar-se, tentando contornar o adversário
          if (e.getDistance() >= 200){
		 //Direciona o robô para direita em direção ao adversário
	     setTurnRight(e.getBearing());
         }else{       
		  //Direciona o robô para esquerda: dividindo Distance (ângulo absoluto) por 4, multiplicando por -1 (inversão do movimento) e 
		  //subtrai pelo ângulo do nosso radar (em radianos)
		 setTurnLeftRadians(Distance / 4  * - 1 - getRadarHeadingRadians());//Isto ajusta para ir em direção do adversário de maneira tática, permitindo esquivas 
         }
		
       //Decide qual o valor do poder de fogo do tiro, utilizado em casos de energia menor que 10. Útil para não esgotar nossa energia tão rapidamente! 
        double Fire = Math.min(1 , getEnergy()/2); //Math.min: Escolhe o menor valor dentre dois, separados por vírgula.
		
       //Se a distância até o outro robô for menor que 200 
        if (e.getDistance() < 200){
	    //Se a energia do nosso robô for maior ou igual que 10
		  if (getEnergy() >= 10){
		 setBulletColor(Color.red); //cor da bala/tiro do robô (Vermelho)
		 // Atira com poder de fogo 3 (máximo)
        fire(3);
		} else{
        setBulletColor(Color.blue); //cor da bala/tiro do robô (Azul)
     	// Atira com poder de fogo determinado pela situação
        fire(Fire);
         }
		}
        //Se não, se a distância até o outro robô for menor ou igual que 300
       else if (e.getDistance() <= 300){
		//Se a energia do nosso robô for maior ou igual que 10
        if (getEnergy() >= 10){
		setBulletColor(Color.orange); //cor da bala/tiro do robô (Laranja)
		 // Atira com poder de fogo 2 
        fire(2);
		}else{
		setBulletColor(Color.blue); //cor da bala/tiro do robô (Azul)
        // Atira com poder de fogo determinado pela situação
        fire(Fire);
        }
         }
	  }  
	
//onHitByBullet: Quando recebemos um tiro de um robô 
public void onHitByBullet(HitByBulletEvent e) {
//Define o boolean como verdadeiro, indicando que deve-se esquivar	
Escape = true; 
     //Ao receber-mos um tiro, exibirá esta mensagem	
System.out.println("Nem doeu!");
}
	

//onHitWall: Quando colidirmos com a parede
public void onHitWall(HitWallEvent e) {
  //tick: Ciclo de atualização do jogo	
 //Realiza o aumento da taxa da rotação do robô, para conseguir desencostar da parede rapidamente;
//Define a velocidade de rotação com o valor retornado que representa a velocidade com que o seu robô está girando em graus por tick + 1,5 graus por tick.
setTurnRate(getTurnRate() + 1.5); 

     //Ao chocar com a parede, exibirá esta mensagem
System.out.println("Maldita parede!");
}	


//onStatus: Mostra os atributos do nosso robô, como energia, eixo X, eixo Y, velocidade, entre outros
  public void onStatus(StatusEvent e) {
        System.out.println("--- Status Atual ---");
        System.out.println("Energia: " + getEnergy());
        System.out.println("Posição X: " + getX());
        System.out.println("Posição Y: " + getY());
        System.out.println("Velocidade: " + getVelocity());
        System.out.println("Direção da Cabeça: " + getGunHeading());
        System.out.println("Direção do Radar: " + getRadarHeading());
        System.out.println("--------------------");
    }	


//onHitRobot: Quando se choca com outro robô
public void onHitRobot(HitRobotEvent e){
    //Ao chocar com outro robô, exibirá esta mensagem
System.out.println("Choquei com outra lata velha!");
}


//onBattleEnded: Quando a batalha termina
public void onBattleEnded(BattleEndedEvent e){
    //Ao finalizar uma batalha, exibirá esta mensagem
System.out.println("Apenas se lutar você poderá vencer!");
}


//onBulletHitBullet: Quando acertamos um tiro em outro robô
public void onBulletHitBullet(BulletHitBulletEvent e){
    //Ao acertar o tiro em algum robô, exibirá esta mensagem
System.out.println("Olha a bala perdida!");
}


//onBulletMissed: Quando erramos um tiro em outro robô
public void onBulletMissed(BulletMissedEvent e){
    //Ao errar o tiro em algum alvo, exibirá esta mensagem
System.out.println("O próximo eu não errarei!");
}


//onDeath: Quando morremos
public void onDeath(DeathEvent e){
    //Ao morrer, exibirá esta mensagem	
System.out.println("Eu voltarei mais forte!");
}


//onRobotDeath: Quando um robô morrer
public void onRobotDeath(RobotDeathEvent e){
	//String para obter o nome do adversário
	String Name = getName();
    //Quando um robô morrer, exibirá esta mensagem
System.out.println("Adeus, " + Name + ". Eu venci!");
}


//onRoundEnded: Quando o round acabar
public void onRoundEnded(RoundEndedEvent e){
    //Ao fim do round, exibirá esta mensagem
System.out.println("Nós fazemos nossa vitória. Bom jogo!");
}


//onWin: Quando vencemos o round
public void onWin(WinEvent e){
    //Quando vencermos o round, exibirá esta mensagem	
System.out.println("Aqueles que não conseguem jogar nada fora, não conseguem mudar nada.");
}
}