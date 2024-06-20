import torch 
import torch.nn as nn

import torch
import torch.nn as nn

class DNN(nn.Module):

    def __init__(self):
        super(DNN, self).__init__()
        self.NN = nn.Sequential(
            nn.Linear(30,512),
            nn.ReLU(),
            nn.Linear(512,256),
            nn.ReLU(),
            nn.Linear(256,10)
        )
        

    def forward(self, x):
        x = self.NN(x)
        return x


model = DNN()
print(model)

t = torch.rand(64,30) #(batch_size,num_features)

print(model(t).shape)
