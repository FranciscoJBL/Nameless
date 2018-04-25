##
Parameters of forward propagation
###
```
PH1  = I[1] * W[1];
PH2  = I[2] * W[2];
PH3  = I[3] * W[3];
PH4  = I[4] * W[4];
```
```
PH5  = I[1] * W[5];
PH6  = I[2] * W[6];
PH7  = I[3] * W[7];
PH8  = I[4] * W[8];
```
```
PH9  = I[1] * W[9];
PH10 = I[2] * W[10];
PH11 = I[3] * W[11];
PH12 = I[4] * W[12];
```
```
H1 = (b1 * ( PH1 + PH2  + PH3   + PH4 );
H2 = (b2 * ( PH5 + PH6  + PH7   + PH8 );
H3 = (b3 * ( PH9 + PH10 + PH11  + PH12 );
```
```
Output = (W13 * H1)+(W14 * H2)+(W15 * H3);
```
###
Being I the inputs, buffer for 4 numbers,
W is the weight of every conection between input and the hidden perceptrons,
PH its the partial hidden perceptrons value PH = input * Weight,
H its the final value of hidden layer, it applies the activation Bias to the partial value of
our single Output its the sum of all three hidden perceptrons multiplied by its respective weights

###
Note that weights are generated random at the start of the training for, later, being updated
in every cycle using back-propagation method. however, even though Bias is generated randomly
at the start too, it is never updated in this model.