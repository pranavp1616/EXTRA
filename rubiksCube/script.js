const N = 3;
const n = N-1;
const CLOCKWISE = 1;
const ANTICLOCKWISE = -1;
const COL_BLUE      = '#0000FF';
const COL_GREEN     = '#008000';
const COL_YELLOW    = '#FFFF00';
const COL_WHITE     = '#D3D3D3'; // pink for white color now
const COL_ORANGE    = '#FFA500';
const COL_RED       = '#FF0000';
var frontMatrix     =     [    [COL_BLUE,COL_BLUE,COL_BLUE],        [COL_BLUE,COL_BLUE,COL_BLUE],       [COL_BLUE,COL_BLUE,COL_BLUE]        ] ;
var backMatrix      =     [    [COL_GREEN,COL_GREEN,COL_GREEN],     [COL_GREEN,COL_GREEN,COL_GREEN],    [COL_GREEN,COL_GREEN,COL_GREEN]     ] ;
var upMatrix        =     [    [COL_YELLOW,COL_YELLOW,COL_YELLOW],  [COL_YELLOW,COL_YELLOW,COL_YELLOW], [COL_YELLOW,COL_YELLOW,COL_YELLOW]  ] ;
var downMatrix      =     [    [COL_WHITE,COL_WHITE,COL_WHITE],     [COL_WHITE,COL_WHITE,COL_WHITE],    [COL_WHITE,COL_WHITE,COL_WHITE]     ] ;
var leftMatrix      =     [    [COL_ORANGE,COL_ORANGE,COL_ORANGE],  [COL_ORANGE,COL_ORANGE,COL_ORANGE], [COL_ORANGE,COL_ORANGE,COL_ORANGE]  ] ;
var rightMatrix     =     [    [COL_RED,COL_RED,COL_RED],           [COL_RED,COL_RED,COL_RED],          [COL_RED,COL_RED,COL_RED]           ] ;

function mySwap(matrix,a,b,c,d){
    var temp = matrix[a][b];
    matrix[a][b]=matrix[c][d];
    matrix[c][d]=temp;
}

function rotateMatrix(matrix, direction){
    var i,j;
    for(i=0;i<N;i++)
        for(j=i;j<N;j++)    mySwap(matrix,i,j,j,i);
    if(direction===CLOCKWISE){ 
        for(i=0;i<N;i++)
            for(j=0;j<N/2;j++)  mySwap(matrix,i,j,i,n-j);
    }else{  // ANTI CLOCKWISE
        for(i=0;i<N;i++)
            for(j=0;j<N/2;j++)  mySwap(matrix,j,i,n-j,i);
    }
}

function frontRotate(direction){
    rotateMatrix(frontMatrix, direction);
    var k,temp=[COL_RED,COL_RED,COL_RED];
    if(direction===CLOCKWISE){
        for(k=0;k<N;k++) temp[k]=upMatrix[n][k];
        for(k=0;k<N;k++) upMatrix[n][k]=leftMatrix[n-k][n];
        for(k=0;k<N;k++) leftMatrix[k][n]=downMatrix[0][k];
        for(k=0;k<N;k++) downMatrix[0][k]=rightMatrix[n-k][0];
        for(k=0;k<N;k++) rightMatrix[k][0]=temp[k];
    }else{
        for(k=0;k<N;k++) temp[k]=upMatrix[n][k];
        for(k=0;k<N;k++) upMatrix[n][k]=rightMatrix[k][0];
        for(k=0;k<N;k++) rightMatrix[k][0]=downMatrix[0][n-k];
        for(k=0;k<N;k++) downMatrix[0][k]=leftMatrix[k][n];
        for(k=0;k<N;k++) leftMatrix[n-k][n]=temp[k];
    }
    renderCube();
}

function backRotate(direction){
    rotateMatrix(backMatrix, direction);
    var k,temp=[COL_RED,COL_RED,COL_RED];
    if(direction===CLOCKWISE){
        for(k=0;k<N;k++) temp[k]=upMatrix[0][k];
        for(k=0;k<N;k++) upMatrix[0][k]=rightMatrix[k][n];
        for(k=0;k<N;k++) rightMatrix[k][n]=downMatrix[n][n-k];
        for(k=0;k<N;k++) downMatrix[n][k]=leftMatrix[k][0];
        for(k=0;k<N;k++) leftMatrix[k][0]=temp[n-k];
    }else{ 
        for(k=0;k<N;k++) temp[k]=upMatrix[0][k];
        for(k=0;k<N;k++) upMatrix[0][k]=leftMatrix[n-k][0];
        for(k=0;k<N;k++) leftMatrix[k][0]=downMatrix[n][k];
        for(k=0;k<N;k++) downMatrix[n][k]=rightMatrix[n-k][n];
        for(k=0;k<N;k++) rightMatrix[k][n]=temp[k];
    }
    renderCube();
}

function upRotate(direction){
    rotateMatrix(upMatrix, direction);
    var k,temp=[COL_RED,COL_RED,COL_RED];
    if(direction===CLOCKWISE){
        for(k=0;k<N;k++) temp[k]=frontMatrix[0][k];
        for(k=0;k<N;k++) frontMatrix[0][k]=rightMatrix[0][k];
        for(k=0;k<N;k++) rightMatrix[0][k]=backMatrix[0][k];
        for(k=0;k<N;k++) backMatrix[0][k]=leftMatrix[0][k];
        for(k=0;k<N;k++) leftMatrix[0][k]=temp[k];
    }else{
        for(k=0;k<N;k++) temp[k]=frontMatrix[0][k];
        for(k=0;k<N;k++) frontMatrix[0][k]=leftMatrix[0][k];
        for(k=0;k<N;k++) leftMatrix[0][k]=backMatrix[0][k];
        for(k=0;k<N;k++) backMatrix[0][k]=rightMatrix[0][k];
        for(k=0;k<N;k++) rightMatrix[0][k]=temp[k];

    }

    renderCube();
}

function downRotate(direction){
    rotateMatrix(downMatrix, direction);
    var k,temp=[COL_RED,COL_RED,COL_RED];
    if(direction===CLOCKWISE){
        for(k=0;k<N;k++) temp[k]=frontMatrix[n][k];
        for(k=0;k<N;k++) frontMatrix[n][k]=leftMatrix[n][k];
        for(k=0;k<N;k++) leftMatrix[n][k]=backMatrix[n][k];
        for(k=0;k<N;k++) backMatrix[n][k]=rightMatrix[n][k];
        for(k=0;k<N;k++) rightMatrix[n][k]=temp[k];
    }else{
        for(k=0;k<N;k++) temp[k]=frontMatrix[n][k];
        for(k=0;k<N;k++) frontMatrix[n][k]=rightMatrix[n][k];
        for(k=0;k<N;k++) rightMatrix[n][k]=backMatrix[n][k];
        for(k=0;k<N;k++) backMatrix[n][k]=leftMatrix[n][k];
        for(k=0;k<N;k++) leftMatrix[n][k]=temp[k];
    }
    renderCube();
}

function leftRotate(direction){
    rotateMatrix(leftMatrix, direction);
    var k,temp=[COL_RED,COL_RED,COL_RED];
    if(direction===CLOCKWISE){
        for(k=0;k<N;k++) temp[k]=upMatrix[k][0];
        for(k=0;k<N;k++) upMatrix[n-k][0]=backMatrix[k][n];
        for(k=0;k<N;k++) backMatrix[k][n]=downMatrix[n-k][0];
        for(k=0;k<N;k++) downMatrix[k][0]=frontMatrix[k][0];
        for(k=0;k<N;k++) frontMatrix[k][0]=temp[k];
    }else{
        for(k=0;k<N;k++) temp[k]=upMatrix[k][0];
        for(k=0;k<N;k++) upMatrix[k][0]=frontMatrix[k][0]
        for(k=0;k<N;k++) frontMatrix[k][0]=downMatrix[k][0];
        for(k=0;k<N;k++) downMatrix[k][0]=backMatrix[n-k][n];
        for(k=0;k<N;k++) backMatrix[k][n]=temp[n-k];
    }
    renderCube();
}

function rightRotate(direction){
    rotateMatrix(rightMatrix, direction);
    var k,temp=[COL_RED,COL_RED,COL_RED];
    if(direction===CLOCKWISE){
        for(k=0;k<N;k++) temp[k]=upMatrix[k][n];
        for(k=0;k<N;k++) upMatrix[k][n]=frontMatrix[k][n];
        for(k=0;k<N;k++) frontMatrix[k][n]=downMatrix[k][n];
        for(k=0;k<N;k++) downMatrix[k][n]=backMatrix[n-k][0];
        for(k=0;k<N;k++) backMatrix[k][0]=temp[n-k];
    }else{
        for(k=0;k<N;k++) temp[k]=upMatrix[k][n];
        for(k=0;k<N;k++) upMatrix[n-k][n]=backMatrix[k][0];
        for(k=0;k<N;k++) backMatrix[k][0]=downMatrix[n-k][n];
        for(k=0;k<N;k++) downMatrix[k][n]=frontMatrix[k][n];
        for(k=0;k<N;k++) frontMatrix[k][n]=temp[k];
    }
    renderCube();
}

/* ============ Render Cube ================== */
const BOX_LEN = 47;
const BOX_BORDER = 2;
const BOX_FINAL_LEN = BOX_LEN-BOX_BORDER;
function renderCube(){
    console.log('rendering...');   
    var ctx ; 
    var upCanvas = document.getElementById('upCanvas');
    ctx = upCanvas.getContext("2d");
    for(var i=0; i<N; i++){ 
        for(var j=0; j<N; j++){
            ctx.fillStyle = upMatrix[i][j];
            ctx.fillRect(   (j*BOX_LEN), (i*BOX_LEN), BOX_FINAL_LEN,BOX_FINAL_LEN );        
        }
    }
    var leftCanvas = document.getElementById('leftCanvas');
    ctx = leftCanvas.getContext("2d");
    for(var i=0; i<N; i++){
        for(var j=0; j<N; j++){
            ctx.fillStyle = leftMatrix[i][j];
            ctx.fillRect(   (j*BOX_LEN), (i*BOX_LEN), BOX_FINAL_LEN, BOX_FINAL_LEN );        
        }
    }
    var frontCanvas = document.getElementById('frontCanvas');
    ctx = frontCanvas.getContext("2d");
    for(var i=0; i<N; i++){
        for(var j=0; j<N; j++){
            ctx.fillStyle = frontMatrix[i][j];
            ctx.fillRect(   (j*BOX_LEN), (i*BOX_LEN), BOX_FINAL_LEN, BOX_FINAL_LEN );        
        }
    }
    var rightCanvas = document.getElementById('rightCanvas');
    ctx = rightCanvas.getContext("2d");
    for(var i=0; i<N; i++){ 
        for(var j=0; j<N; j++){
            ctx.fillStyle = rightMatrix[i][j];
            ctx.fillRect(   (j*BOX_LEN), (i*BOX_LEN), BOX_FINAL_LEN, BOX_FINAL_LEN );        
        }
    }
    var backCanvas = document.getElementById('backCanvas');
    ctx = backCanvas.getContext("2d");
    for(var i=0; i<N; i++){
        for(var j=0; j<N; j++){
            ctx.fillStyle = backMatrix[i][j];
            ctx.fillRect(   (j*BOX_LEN), (i*BOX_LEN), BOX_FINAL_LEN, BOX_FINAL_LEN );        
        }
    }
    var downCanvas = document.getElementById('downCanvas');
    ctx = downCanvas.getContext("2d");
    for(var i=0; i<N; i++){ 
        for(var j=0; j<N; j++){
            ctx.fillStyle = downMatrix[i][j];
            ctx.fillRect(   (j*BOX_LEN), (i*BOX_LEN), BOX_FINAL_LEN, BOX_FINAL_LEN );        
        }
    }
}

function buttonResetCube(){
    frontMatrix     =     [    [COL_BLUE,COL_BLUE,COL_BLUE],         [COL_BLUE,COL_BLUE,COL_BLUE],       [COL_BLUE,COL_BLUE,COL_BLUE]        ] ;
    backMatrix      =     [    [COL_GREEN,COL_GREEN,COL_GREEN],     [COL_GREEN,COL_GREEN,COL_GREEN],    [COL_GREEN,COL_GREEN,COL_GREEN]     ] ;
    upMatrix        =     [    [COL_YELLOW,COL_YELLOW,COL_YELLOW],  [COL_YELLOW,COL_YELLOW,COL_YELLOW], [COL_YELLOW,COL_YELLOW,COL_YELLOW]  ] ;
    downMatrix      =     [    [COL_WHITE,COL_WHITE,COL_WHITE],     [COL_WHITE,COL_WHITE,COL_WHITE],    [COL_WHITE,COL_WHITE,COL_WHITE]     ] ;
    leftMatrix      =     [    [COL_ORANGE,COL_ORANGE,COL_ORANGE],  [COL_ORANGE,COL_ORANGE,COL_ORANGE], [COL_ORANGE,COL_ORANGE,COL_ORANGE]  ] ;
    rightMatrix     =     [    [COL_RED,COL_RED,COL_RED],           [COL_RED,COL_RED,COL_RED],          [COL_RED,COL_RED,COL_RED]           ] ;
    renderCube();
}

// MAIN ALGORITHM
function buttonSolveCube(){
    alert('TEST');
}

/*======== main() function ========*/
renderCube();
