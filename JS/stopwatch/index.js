<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Stop Watch</title>
    <link rel="stylesheet" type="text/css" href="./style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</head>
<body>
    <h5 class="d-flex justify-content-center mt-3 mb-2">
        STOP WATCH
    </h5>
    <div class="container">
        <div class="row">
            <div class="col-12 d-flex justify-content-center mt-50">
                <h1 id="min">0</h1>
                <h1 id="sec">0</h1>
                <h1 id="msec">0</h1>
            </div>
        </div>
        <div class="row">
            <div class="col-12 d-flex justify-content-center" id="btn">
                <button class="btn" onclick="start()" id="start">Start</button>
                <button class="ml-3 btn" onclick="pause()" id="pause" disabled>Pause</button>
                <button class="ml-3 btn" id="reset" onclick="reset()" disabled>Reset</button>
                <button class="ml-3 btn" id="save" onclick="save()" disabled><i class="fa fa-bookmark fa-2x"></i></button>
            </div>
        </div>
        <div class="row">
            <div class="col-12" id="record">
                <table class="table" id="table">
                    <tbody>
                    </tbody>
                </table>
            </div>
        </div>
    </div>
    <script type="text/javascript" src="app.js"></script> 
</body>
</html>
