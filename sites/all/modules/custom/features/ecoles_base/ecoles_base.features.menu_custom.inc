<?php
/**
 * @file
 * ecoles_base.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ecoles_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ecoles-menu.
  $menus['menu-ecoles-menu'] = array(
    'menu_name' => 'menu-ecoles-menu',
    'title' => 'Ecole menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ecole menu');

  return $menus;
}
