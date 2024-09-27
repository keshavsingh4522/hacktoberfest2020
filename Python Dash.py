import dash
import dash_core_components as dcc
import dash_html_components as html

app = dash.Dash()

fnameDict = {'chriddy': ['opt1_c', 'opt2_c', 'opt3_c'], 'jackp': ['opt1_j', 'opt2_j']}

names = list(fnameDict.keys())
nestedOptions = fnameDict[names[0]]
print([{'label':opt, 'value':opt} for opt in nestedOptions])

app.layout = html.Div(
    [
        html.Div([
        dcc.Dropdown(
            id='name-dropdown',
            options=[{'label': 'chriddy', 'value': 'chriddy'}, {'label': 'jackp', 'value': 'jackp'}],
            value = ""
            ),
            ],style={'width': '20%', 'display': 'inline-block'}),
        html.Div([
        dcc.Dropdown(
            id='opt-dropdown',
            options=[{'label': 'opt1_c', 'value': 'opt1_c'}, {'label': 'opt2_c', 'value': 'opt2_c'}, {'label': 'opt3_c', 'value': 'opt3_c'}],
            value = ""
            ),
            ],style={'width': '20%', 'display': 'inline-block'}
        ),
        html.Div([
        dcc.Dropdown(
            id='second-opt',
            options=[{'label': 'val1_c', 'value': 'val1_c'}],
            value = ""
            ),
            ],style={'width': '20%', 'display': 'inline-block'}
        ),
    ]
)



@app.callback(
    dash.dependencies.Output('opt-dropdown', 'options'),
    [dash.dependencies.Input('name-dropdown', 'value')]
)
def update_date_dropdown(name):
    ##opts = fnameDict[name]
    if(name=='chriddy'):
        options=[{'label': 'opt4_c', 'value': 'opt4_c'}]
    else:
        options=[{'label': 'opt5_c', 'value': 'opt5_c'}]

    return options

@app.callback(
    dash.dependencies.Output('second-opt', 'options'),
    [dash.dependencies.Input('opt-dropdown', 'value')]
)
def update_date_dropdown2(name):
    ##opts = fnameDict[name]
    if(name=='opt5_c'):
        options=[{'label': 'abc', 'value': 'abc'}]
    else:
        options=[{'label': 'xyz', 'value': 'xyz'}]
    print(options)

    return options


if __name__ == '__main__':
    app.run_server(debug=True)