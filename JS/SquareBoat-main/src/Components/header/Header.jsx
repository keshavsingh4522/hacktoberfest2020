import React from 'react'
import {Link} from 'react-router-dom'
import { styled } from '@mui/material/styles';
import AppBar from '@mui/material/AppBar';
import Box from '@mui/material/Box';
import Toolbar from '@mui/material/Toolbar';
import Typography from '@mui/material/Typography';
import Button from '@mui/material/Button';
import Menu from '@mui/material/Menu';
import MenuItem from '@mui/material/MenuItem';
import Avatar from "@mui/material/Avatar";
import KeyboardArrowDownIcon from '@mui/icons-material/KeyboardArrowDown';
import { useHistory } from "react-router-dom";
import './Header.css';

const StyledToolbar = styled(Toolbar)(({ theme }) => ({
  alignItems: 'flex-start',
  paddingTop: theme.spacing(1),
  paddingBottom: theme.spacing(2),
  // Override media queries injected by theme.mixins.toolbar
  '@media all': {
    minHeight: 250,
  },
}));
function Header(props) {
  let history = useHistory();
  const [anchorEl, setAnchorEl] = React.useState(null);
  const open = Boolean(anchorEl);
  const handleClick = (event) => {
    setAnchorEl(event.currentTarget);
  };
  const handleClose = () => {
    setAnchorEl(null);
    history.push('/logout');
  };

      return (
        <Box sx={{ flexGrow: 1 }} className="navbox">
  <AppBar position="static" className="navbar">
    <StyledToolbar>
    <Typography
            variant="h6"
            noWrap
            component="div"
            sx={{ flexGrow: 1, display: { xs: 'none', sm: 'block' } }}
            className='title'
          >
            MY<span className='job'>JOBS</span>
          </Typography>
      {props.loggedIn?(<div className='logins'><Button
        id="basic-button"
        aria-controls={open ? 'basic-menu' : undefined}
        aria-haspopup="true"
        aria-expanded={open ? 'true' : undefined}
        onClick={handleClick}
      >
        <Avatar>H</Avatar><KeyboardArrowDownIcon/>
      </Button>
      <Menu
        id="basic-menu"
        anchorEl={anchorEl}
        open={open}
        onClose={handleClose}
        MenuListProps={{
          'aria-labelledby': 'basic-button',
        }}
      >
        <MenuItem onClick={handleClose}> Logout</MenuItem>
      </Menu></div>):(<Button className='btn'><Link to='/login' className='log'>LogIn/SignUp</Link></Button>)}
    </StyledToolbar>
  </AppBar>
</Box>
      )
}

export default Header
