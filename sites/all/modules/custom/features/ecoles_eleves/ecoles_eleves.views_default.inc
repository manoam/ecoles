<?php
/**
 * @file
 * ecoles_eleves.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ecoles_eleves_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'liste_des_eleves';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_eleve';
  $view->human_name = 'Liste des élèves';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Liste de touts élèves';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Eleve: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_eleve';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: eleve: Num Mat */
  $handler->display->display_options['fields']['field_num_mat']['id'] = 'field_num_mat';
  $handler->display->display_options['fields']['field_num_mat']['table'] = 'field_data_field_num_mat';
  $handler->display->display_options['fields']['field_num_mat']['field'] = 'field_num_mat';
  $handler->display->display_options['fields']['field_num_mat']['label'] = 'Num Matricule';
  $handler->display->display_options['fields']['field_num_mat']['type'] = 'text_plain';
  /* Field: eleve: Nom */
  $handler->display->display_options['fields']['field_nom']['id'] = 'field_nom';
  $handler->display->display_options['fields']['field_nom']['table'] = 'field_data_field_nom';
  $handler->display->display_options['fields']['field_nom']['field'] = 'field_nom';
  /* Field: eleve: Prénom */
  $handler->display->display_options['fields']['field_prenom']['id'] = 'field_prenom';
  $handler->display->display_options['fields']['field_prenom']['table'] = 'field_data_field_prenom';
  $handler->display->display_options['fields']['field_prenom']['field'] = 'field_prenom';
  /* Field: eleve: Date Naiss */
  $handler->display->display_options['fields']['field_date_naiss']['id'] = 'field_date_naiss';
  $handler->display->display_options['fields']['field_date_naiss']['table'] = 'field_data_field_date_naiss';
  $handler->display->display_options['fields']['field_date_naiss']['field'] = 'field_date_naiss';
  $handler->display->display_options['fields']['field_date_naiss']['label'] = 'Date de naissance';
  $handler->display->display_options['fields']['field_date_naiss']['settings'] = array(
    'format_type' => 'date',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: eleve: Tel */
  $handler->display->display_options['fields']['field_tel']['id'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['table'] = 'field_data_field_tel';
  $handler->display->display_options['fields']['field_tel']['field'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['label'] = 'Téléphone';
  /* Field: Eleve: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_eleve';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'Voire';
  /* Filter criterion: Eleve: eleve type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_eleve';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'eleve' => 'eleve',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: eleve: Num Mat (field_num_mat) */
  $handler->display->display_options['filters']['field_num_mat_value']['id'] = 'field_num_mat_value';
  $handler->display->display_options['filters']['field_num_mat_value']['table'] = 'field_data_field_num_mat';
  $handler->display->display_options['filters']['field_num_mat_value']['field'] = 'field_num_mat_value';
  $handler->display->display_options['filters']['field_num_mat_value']['group'] = 1;
  $handler->display->display_options['filters']['field_num_mat_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_num_mat_value']['expose']['operator_id'] = 'field_num_mat_value_op';
  $handler->display->display_options['filters']['field_num_mat_value']['expose']['label'] = 'Num Matricules';
  $handler->display->display_options['filters']['field_num_mat_value']['expose']['operator'] = 'field_num_mat_value_op';
  $handler->display->display_options['filters']['field_num_mat_value']['expose']['identifier'] = 'field_num_mat_value';
  $handler->display->display_options['filters']['field_num_mat_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: eleve: Nom (field_nom) */
  $handler->display->display_options['filters']['field_nom_value']['id'] = 'field_nom_value';
  $handler->display->display_options['filters']['field_nom_value']['table'] = 'field_data_field_nom';
  $handler->display->display_options['filters']['field_nom_value']['field'] = 'field_nom_value';
  $handler->display->display_options['filters']['field_nom_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_nom_value']['group'] = 1;
  $handler->display->display_options['filters']['field_nom_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_nom_value']['expose']['operator_id'] = 'field_nom_value_op';
  $handler->display->display_options['filters']['field_nom_value']['expose']['label'] = 'Nom (Anarana)';
  $handler->display->display_options['filters']['field_nom_value']['expose']['operator'] = 'field_nom_value_op';
  $handler->display->display_options['filters']['field_nom_value']['expose']['identifier'] = 'field_nom_value';
  $handler->display->display_options['filters']['field_nom_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: eleve: Prénom (field_prenom) */
  $handler->display->display_options['filters']['field_prenom_value']['id'] = 'field_prenom_value';
  $handler->display->display_options['filters']['field_prenom_value']['table'] = 'field_data_field_prenom';
  $handler->display->display_options['filters']['field_prenom_value']['field'] = 'field_prenom_value';
  $handler->display->display_options['filters']['field_prenom_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_prenom_value']['group'] = 1;
  $handler->display->display_options['filters']['field_prenom_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_prenom_value']['expose']['operator_id'] = 'field_prenom_value_op';
  $handler->display->display_options['filters']['field_prenom_value']['expose']['label'] = 'Prénom (fanampin\'anarana)';
  $handler->display->display_options['filters']['field_prenom_value']['expose']['operator'] = 'field_prenom_value_op';
  $handler->display->display_options['filters']['field_prenom_value']['expose']['identifier'] = 'field_prenom_value';
  $handler->display->display_options['filters']['field_prenom_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'liste/eleves';
  $export['liste_des_eleves'] = $view;

  return $export;
}
