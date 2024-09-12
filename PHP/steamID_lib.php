<?php
// library made by thexkey
// allows you to check if a STEAMID is 32/64, allows conversion and allows you to grab the avatar/data of a user.
// Requires PHP 5 or higher and a Steam API key.
class steam
{
    public function __construct()
    {
        global $cfg;

        $this->apikey 	= "Your_Steam_API_Key_Here";

        $this->url 		= "";

        $this->dir  	= "";
    }





    // SteamIDs

    public function IsSteamID32($input)
    {
        return stristr(trim($input), 'STEAM_0:');
    }
    public function IsSteamID64($input)
    {
        return (strlen(trim($input)) == 17);
    }
    public function SteamIDTo32($steamid64)
    {
        $steamid64 = trim($steamid64);

        $steamId1  = substr($steamid64, -1) % 2;

        $steamId2a = intval(substr($steamid64, 0, 4)) - 7656;

        $steamId2b = substr($steamid64, 4) - 1197960265728;

        $steamId2b = $steamId2b - $steamId1;



        if ($steamId2a <= 0 && $steamId2b <= 0) {
            die("SteamID $steamid64 is too small.");
        }



        return "STEAM_0:$steamId1:" . (($steamId2a + $steamId2b) / 2);
    }



    public function SteamIDTo64($steamid32)
    {
        $steamid32 = trim($steamid32);

        if ($steamid32 == 'STEAM_ID_LAN' || $steamid32 == 'BOT') {
            die("Cannot convert SteamID \"$steamid32\" to a community ID.");
        }

        if (!$this->IsSteamID32($steamid32)) {
            die("SteamID \"$steamid32\" doesn't have the correct format.");
        }



        $steamid32 = explode(':', substr($steamid32, 6));

        $steamid32 = $steamid32[1] + $steamid32[2] * 2 + 1197960265728;



        return '7656' . $steamid32;
    }



    public function GetXMLURL($info)
    {
        if (stristr($info, 'http://steamcommunity.com/id/')) {
            return 'http://steamcommunity.com/id/' . str_ireplace('http://steamcommunity.com/id/', '', $info) . '?xml=1';
        } elseif (stristr($info, 'http://steamcommunity.com/profiles/')) {
            return 'http://steamcommunity.com/profiles/' . str_ireplace('http://steamcommunity.com/profiles/', '', $info) . '?xml=1';
        } elseif ($this->IsSteamID32($info)) {
            return 'http://steamcommunity.com/profiles/' . $this->SteamIDTo64($info) . '?xml=1';
        } elseif ($this->IsSteamID64($info)) {
            return 'http://steamcommunity.com/profiles/' . $info . '?xml=1';
        }
    }



    public function NameID($name, $steamid64)
    {
        return '<a href="http://steamcommunity.com/profiles/' . $steamid64 . '/">' . $name . '</a>';
    }





    // Avatars
    // this took me a while to figure out since steam's api is not reliable for grabbing avatars.

    public function GetAvatar($steamid64, $max_age = null)
    {
        $file = $this->dir . '/cache/avatars/' . $steamid64 . '.jpg';

        $cache = $_SERVER['DOCUMENT_ROOT'] . $file;

        if (($max_age == null) or (file_exists($cache) && (filemtime($cache) >= time() - $max_age))) { # If max age is null we'll assume we're using this somewhere that'd only be used if you'd have joined the server.

            return $this->url . $file;
        } else {
            libxml_use_internal_errors(true);

            $xml = simplexml_load_file('https://steamcommunity.com/profiles/' . $steamid64 . '?xml=1');

            $avatar = htmlentities($xml->avatarFull);



            if ($avatar == null) {
                return $this->url . $this->dir . '/static/images/avatar_unknown.jpg';
            } else {
                $ch = curl_init($avatar);

                $fp = fopen($cache, 'wb');

                curl_setopt($ch, CURLOPT_FILE, $fp);

                curl_setopt($ch, CURLOPT_HEADER, 0);

                curl_exec($ch);

                curl_close($ch);

                fclose($fp);

                return  $this->url . $file;
            }
        }
    }
}
