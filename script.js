/*Main class Game core*/
class Functionality {
  constructor(gameLogBox) {
    this.gameLogBox = gameLogBox
  }

  main(){
    /*DATA*/
    let nHands = 8; /* number of playing hands */
    var sequence = []; /*the flow of the game, it has 7 elements and the element that is zero indicates whose Play is*/ 
    sequence.length = nHands
    var nTurn; /*the hand number whose Play is (from 0 to 7)*/
    var rightOrLeft; /* direction of the flow, 1 is right, -1 is left;*/
    var skill; /*type of tap by the user, 0 is two taps reversing, 1 is a single tap, 2 is three taps skipping one player.*/
    var i; /*just a variable for loops*/
    var lost = false; /*is true when user loses*/

    //initial values
    nTurn = 0;  //stars with sequende element 0: the user left hand
    rightOrLeft = 1; //flow starts going to the right
    //initial values

 

      /*Here goes the actual code*/
    }
  }

  gameLog(nPlay) {
    switch(nPlay) {
      case 0:
        this.gameLogBox.innerText = "Your left hand has"
        break;
      case 1:
        this.gameLogBox.innerText = "Bot1 (right hand) has"
        break;
      case 2:
        this.gameLogBox.innerText = "Bot2 (left hand) has"
        break;
      case 3:
        this.gameLogBox.innerText = "Your right hand has"
        break;
      case 4:
        this.gameLogBox.innerText = "Bot3 (left hand) has"
        break;
      case 5:
        this.gameLogBox.innerText = "Bot2 (right hand) has"
        break;
      case 6:
        this.gameLogBox.innerText = "Bot1 (left hand) has"
        break;
      case 7:
        this.gameLogBox.innerText = "Bot3 (right hand) has"
      default:  "You will start the game with your left hand. The flow starts to you right!"
    }
  }

  lostDecision(nTurn,nPlay) {
    if (nTurn != nPlay) this.gameLogBox.innerText = "YOU LOST!!"
  }


}

/*Data linked from index2.html*/
const lefthandButton = document.querySelector('[data-btnLefthand]')
const righthandButton = document.querySelector('[data-btnRighthand]')
const gameLogBox = document.querySelector('[data-gameLogBox]')
const userPlayBox = document.querySelector('[data-userPlayBox]')
const startButton = document.querySelector('[data-startButton]')


/*Defining class as the game core*/
const functionality = new Functionality(gameLogBox)

/*Events from index2.html*/
startButton.addEventListener('click', button => {
  functionality.main()
})
lefthandButton.addEventListener('click', button => {
  functionality.gameLog(0)
  functionality.lostDecision(nTurn,0)
})
righthandButton.addEventListener('click', button => {
  functionality.gameLog(3)
  functionality.lostDecision(nTurn,3)
})





