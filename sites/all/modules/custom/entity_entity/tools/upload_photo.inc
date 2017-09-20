<?php

function _upload_photo(&$form, &$form_state) {
    
    $destination= variable_get('PUBLIC_FILE','public://').$form_state['destination_photo'];
    $form_name  = $form_state['form_name'];
    $return     = NULL;
    
    $validators = array(
        'file_validate_extensions' => array('jpeg JPG jpg png gif JPEG'),
    );

    if ( $file = file_save_upload($form_name, $validators, $destination, FILE_EXISTS_REPLACE) ) {
        $return = $file->destination;
    }
    else {
        drupal_set_message(t('Impossible de copier la photo'),'error');
    }
    
    return $return;
}


function _upload_photo_compress_and_copy_image($source_file, $destination_file, $newWidth = '350') {
    
    $info = getimagesize($source_file);
    
    switch($info['mime']){
        case 'image/jpeg':
                $image_create_func = 'imagecreatefromjpeg';
                $image_save_func = 'imagejpeg';
                $new_image_ext = 'jpg';
                break;

        case 'image/png':
                $image_create_func = 'imagecreatefrompng';
                $image_save_func = 'imagepng';
                $new_image_ext = 'png';
                break;

        case 'image/gif':
                $image_create_func = 'imagecreatefromgif';
                $image_save_func = 'imagegif';
                $new_image_ext = 'gif';
                break;

        default: 
                throw new Exception(t('Type de fichier inconnu !'));
    }
    
    $img = $image_create_func($source_file);
    list($width, $height) = getimagesize($source_file);
    
    if($height > $width){
        $newHeight = ($height / $width) * $newWidth;
    }else {
        $newHeight = ($width / $height) * $newWidth;
    }
    $tmp = imagecreatetruecolor($newWidth, $newHeight);
    
    // vakiana ilay donnée miaraka amin'ilay image
    // manao error fona dia najanona ity 
//    if(function_exists("exif_read_data")){ 
//        $exif = exif_read_data($source_file); 
//        if(!empty($exif['Orientation'])) { 
//            //jerena raha misy ilay orientation'ilay image ka raha misy dia avadika araka izay ilay sary
//            switch($exif['Orientation']) { 
//            case 3: 
//                $img = imagerotate($img,180,0); 
//                imagecopyresampled($tmp, $img, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
//                break; 
//            case 6: 
//                $img = imagerotate($img,-90,0); 
//                imagecopyresampled($tmp, $img, 0, 0, 0, 0, $newWidth, $newHeight, $height, $width);
//                break; 
//            case 8: 
//                $img = imagerotate($img,90,0); 
//                imagecopyresampled($tmp, $img, 0, 0, 0, 0, $newWidth, $newHeight, $height, $width);
//                break; 
//            default : 
//                imagecopyresampled($tmp, $img, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
//                break;
//            }
//        }else {
//            // misy sary tsy hita ny orientation-ny satria mety efa ntreter-na tamin'ny photoshop ohatra
//            imagecopyresampled($tmp, $img, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
//        }
//    } 
    
    imagecopyresampled($tmp, $img, 0, 0, 0, 0, $newWidth, $newHeight, $width, $height);
    
    if (file_exists($destination_file)) {
        unlink($destination_file);
    }
    
    $image_save_func($tmp, $destination_file);
    
    
    if (file_exists($source_file)) {
        unlink($source_file);
    }
    
    
}
