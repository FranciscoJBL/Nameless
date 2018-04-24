##
Parameters of forward propagation
###
```
$ph1  = i1 * w1;
$ph2  = i2 * w2;
$ph3  = i3 * w3;
$ph4  = i4 * w4;
```
```
$ph5  = i1 * w5;
$ph6  = i2 * w6;
$ph7  = i3 * w7;
$ph8  = i4 * w8;
```
```
$ph9  = i1 * w9;
$ph10 = i2 * w10;
$ph11 = i3 * w11;
$ph12 = i4 * w12;
```
```
$h1 = (b1* ( ph1 + ph2  + ph3   + ph4 );
$h2 = (b2* ( ph5 + ph6  + ph7   + ph8 );
$h3 = (b3* ( ph9 + ph10 + ph11  + ph12 );
```
```
$output = (w13*h1)+(w14*h2)+(w15*h3);
```
###
being i the inputs, buffer for 4 numbers,
w is the weight of every conection between input and the hidden perceptrons
ph partial hidden perceptron value, ph = input*weight
h its the final value of hidden layer, it applies the activation bias to the partial value
our single output its the sum of all three hidden perceptrons multiplied by its respective weights

###
note that weights are generated random at the start of the training for, later, being updated
in every cycle using back-propagation method. however, even though bias is generated randomly
at the start too, it is never updated in this model.